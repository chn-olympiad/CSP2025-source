#include <bits/stdc++.h>
using namespace std;

int n;
int vec[100005][3];

int func(int d1, int d2, int d3, int p, int sum) {
    int r1, r2, r3;
    r1 = r2 = r3 = 0;
    if (p == n) return sum;
    if (d1 < n / 2) r1 = func(d1 + 1, d2, d3, p + 1, sum + vec[p][0]);
    if (d2 < n / 2) r2 = func(d1, d2 + 1, d3, p + 1, sum + vec[p][1]);
    if (d3 < n / 2 && d3 != -1) r3 = func(d1, d2, d3 + 1, p + 1, sum + vec[p][2]);
    return max(max(r1, r2), r3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T, a;
    tuple<int, int, int> p;
    cin >> T;

    while (T--) {
        cin >> n;
        for (int j = 0; j < 3; j++) {
            cin >> vec[0][j];
        }
        if (n <= 30 || (vec[0][2] == 0 && vec[0][1] != 0)) {
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> vec[i][j];
                }
            }
            int res;
            if (vec[0][2] == 0) res = func(0, 0, -1, 0, 0);
            else res = func(0, 0, 0, 0, 0);
            cout << res << endl;
        } else {
            int sum = 0;
            priority_queue<tuple<int, int, int>> pq;
            vector<int> dpt(3, 0); // 各部门人数
            unordered_set<int> psn; // 已安排的成员编号
            for (int j = 0; j < 3; j++) {
                pq.push({vec[0][j], 0, j});
            }
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> a;
                    pq.push({a, i, j});
                }
            }
            
            while (psn.size() < n) {
                p = pq.top();
                pq.pop();
                if (psn.find(get<1>(p)) != psn.end()) continue;
                if (dpt[get<2>(p)] >= n / 2) continue;
                psn.insert(get<1>(p));
                dpt[get<2>(p)]++;
                sum += get<0>(p);
            }
            
            cout << sum << endl;
        }
    }
    return 0;
}