#include <bits/stdc++.h>

std::map<int, std::pair<int, std::pair<int, int>>> stu2m;
//std::map<int, std::vector<std::pair<int,std::pair<int,int>>>> stu2m;
int c = 0;

void solve(int val, int i, int n, int lcount, int mcount, int rcount) {
    if (i == n) {
        c = std::max(c, val);
        return;
    }
    if (lcount < (n/2)) {
        solve(val + stu2m[i].first, i + 1, n, lcount+1, mcount, rcount);
    }
    if (mcount < (n/2)) {
        solve(val + stu2m[i].second.first, i + 1, n, lcount, mcount+1, rcount);
    }
    if (rcount < (n/2)) {
        solve(val + stu2m[i].second.second, i + 1, n, lcount, mcount, rcount+1);
    }
}


/*
int get_comp(int a, int b) {
    if (a == 0) {
        if (b == 1) return 2;
        if (b == 2) return 1;
        return 0;
    }
    if (a == 1) {
        if (b == 0) return 2;
        if (b == 2) return 0;
        return 1;
    }
    if (a == 2) {
        if (b == 0) return 1;
        if (b == 1) return 0;
        return 2;
    }
    return -1;
}
*/


int main() {
    freopen("club.in","r",stdin);
    freopen("club.out", "w",stdout);
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        std::cin >> n;

        std::vector<int> clubs[3] = {{}, {}, {}};
        std::map<int, std::queue<std::pair<int, int>>> m2Stu;
        std::map<int, bool> stus;
        std::set<int> mSet;

        for (int j = 0; j < n; j++) {
            int a1, a2, a3;
            std::cin >> a1 >> a2 >> a3;
/*
            m2Stu[a1].push(std::make_pair(j,0));
            m2Stu[a2].push(std::make_pair(j,1));
            m2Stu[a3].push(std::make_pair(j,2));
            stus[j] = false;
            mSet.insert(a1);
            mSet.insert(a2);
            mSet.insert(a3);
            stu2m[j] = {std::make_pair((a2 > a3)?2:3,std::make_pair(std::min(a1 - a2, a1 - a3), std::max(a1 - a2, a1 - a3))), std::make_pair((a1 > a3)?1:3,std::make_pair(std::min(a2 - a1, a2 - a3), std::max(a2 - a1, a2 - a3))),
                std::make_pair((a1 > a2)?1:2,std::make_pair(std::min(a3 - a1, a3 - a2), std::max(a3 - a1, a3 - a2)))};
*/
            stu2m[j] = std::make_pair(a1, std::make_pair(a2, a3));
        }
/*
        std::vector<int> v(mSet.size());for (int a: mSet) v.push_back(a);
        std::sort(v.begin(), v.end());
        int c = 0;
        bool flag = false;
        do {
            for (int j = v.size() - 1; j >= 0; j--) {
                while (!m2Stu[v[j]].empty()) {
                    std::pair<int, int> p = m2Stu[v[j]].front();
                    m2Stu[v[j]].pop();
                    if (!stus[p.first]) {
                        std::vector<int>& vv = clubs[p.second];
                        if (vv.size() < (n/2)) {
                            vv.push_back(p.first);
                            stus[p.first] = true;
                            c += v[j];
                        } else {
                            for (int k = 0; k < vv.size(); k++) {
                                if (stu2m[vv[k]][p.second].second.first < v[j]) {
                                    if (clubs[stu2m[vv[k]][p.second].first].size() < (n/2)) {
                                        stus[p.first] = true;
                                        clubs[stu2m[vv[k]][p.second].first].push_back(vv[k]);
                                        c = c - stu2m[vv[k]][p.second].second.first + v[j];
                                        vv[k] = p.first;
                                        break;
                                    } else if (stu2m[vv[k]][p.second].second.second < v[j]){
                                        stus[p.first] = true;
                                        clubs[get_comp(p.second,stu2m[vv[k]][p.second].first)].push_back(vv[k]);
                                        c = c - stu2m[vv[k]][p.second].second.second + v[j];
                                        vv[k] = p.first;
                                        stus[p.first] = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } while (flag);*/
        c = 0;
        solve(0, 0, n, 0, 0, 0);
        std::cout << c << std::endl;
        stu2m.clear();
    }
    return 0;
}
