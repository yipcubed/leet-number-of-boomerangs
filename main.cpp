#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/number-of-boomerangs/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int distance(vector<int> &v1, vector<int> &v2) {
        int xdist = v1[0] - v2[0];
        int ydist = v1[1] - v2[1];
        return xdist * xdist + ydist * ydist;
    }


    int numberOfBoomerangs(vector<vector<int>> &points) {
        if (points.size() < 3) return 0;
        int count = 0;
        vector<int> d(500);
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                int xdist = points[i][0] - points[j][0];
                int ydist = points[i][1] - points[j][1];
                d[j] = xdist * xdist + ydist * ydist;
            }
            // only sort the relevant section of d
            sort(d.begin(), d.begin() + points.size());
            int seen = 1;
            for (int k = 1; k < points.size(); ++k) {
                if (d[k] == d[k - 1]) {
                    ++seen;
                } else {
                    count += seen * (seen - 1);
                    seen = 1;
                }
            }
            // take care of the last ones, such as 3s below
            // { 0, 1, 1, 2, 2, 3, 3, 3}
            count += seen * (seen - 1);
        }
        return count;
    }
//    int numberOfBoomerangs(vector<vector<int>> &points) {
//        if (points.size() < 3) return 0;
//        int count = 0;
//        map<vector<int,int>
//        for (int i = 0; i < points.size() - 2; ++i) {
//            for (int j = i + 1; j < points.size() - 1; ++j) {
//                int distij = distance(points[i], points[j]);
//                for (int k = j + 1; k < points.size(); ++k) {
//                    int distik = distance(points[i], points[k]);
//                    int distjk = distance(points[j], points[k]);
//                    if (distik == distjk)
//                        count += 2;
//                    if (distij == distik)
//                        count += 2;
//                    if (distjk == distij)
//                        count += 2;
//                }
//            }
//        }
//        return count;
//    }
};

void test1() {
    vector<vector<int>> v1{
            vector<int>{0, 0},
            vector<int>{1, 0},
            vector<int>{2, 0}
    };

    cout << "2 ? " << Solution().numberOfBoomerangs(v1) << endl;

    vector<vector<int>> v2{
            vector<int>{0, 0},
            vector<int>{1, 0},
            vector<int>{-1, 0},
            vector<int>{0, 1},
            vector<int>{0, -1}
    };

    cout << "20 ? " << Solution().numberOfBoomerangs(v2) << endl;
}

void test2() {

}

void test3() {

}