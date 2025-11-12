#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
int a[100010][3];
struct N
{
    int id, num, nxt;
    bool operator<(const N &b) const {
        return num > b.num;
    }
};
priority_queue<N> pq1, pq2, pq3;
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
        while(!pq1.empty()) pq1.pop();
        while(!pq2.empty()) pq2.pop();
        while(!pq3.empty()) pq3.pop();
        int s = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
                if(a[i][1] >= a[i][2]) {
                    pq1.push({i, a[i][0] - a[i][1], 1});
                }
                else {
                    pq1.push({i, a[i][0] - a[i][2], 2});
                }
                s += a[i][0];
                if(pq1.size() > n / 2) {
                    int t = pq1.top().id, t2 = pq1.top().nxt;
                    pq1.pop();
                    s -= a[t][0];
                    s += a[t][t2];
                    if(t2 == 1) {
                        pq2.push({t, a[t][1] - a[t][2], 2});
                    }
                    else {
                        pq3.push({t, a[t][2] - a[t][1], 1});
                    }
                }
            }
            else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
                if(a[i][0] >= a[i][2]) {
                    pq2.push({i, a[i][1] - a[i][0], 0});
                }
                else {
                    pq2.push({i, a[i][1] - a[i][2], 2});
                }
                s += a[i][1];
                if(pq2.size() > n / 2) {
                    int t = pq2.top().id, t2 = pq2.top().nxt;
                    pq2.pop();
                    s -= a[t][1];
                    s += a[t][t2];
                    if(t2 == 0) {
                        pq1.push({t, a[t][0] - a[t][2], 2});
                    }
                    else {
                        pq3.push({t, a[t][2] - a[t][0], 0});
                    }
                }
            }
            else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][0]) {
                if(a[i][0] >= a[i][1]) {
                    pq3.push({i, a[i][2] - a[i][0], 0});
                }
                else {
                    pq3.push({i, a[i][2] - a[i][1], 1});
                }
                s += a[i][2];
                if(pq3.size() > n / 2) {
                    int t = pq3.top().id, t2 = pq3.top().nxt;
                    pq3.pop();
                    s -= a[t][2];
                    s += a[t][t2];
                    if(t2 == 0) {
                        pq1.push({t, a[t][0] - a[t][1], 1});
                    }
                    else {
                        pq2.push({t, a[t][1] - a[t][0], 0});
                    }
                }
            }
        }
        cout << s << '\n';
    }
    return 0;
}