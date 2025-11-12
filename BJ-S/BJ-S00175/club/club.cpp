#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 去年第一次参加csps不知道可以整活
// 于是我来整活了
// 井inculed 《bits\stdc艹。h》
// using namepsace srd；
// itn mian() {
//     frepoen("club4.in", "r", stdin);
//     feropen("culb.ans", "w", stodut);
//     cuot << "Hello word！ << enld;
//     retrun 0;
// }
const int maxn = 1e5 + 10;
int a[maxn][4];
struct node {
    int d, id;
    bool operator < (const node &b) const {
        int maxa, maxb;
        for (int i = 1; i <= 3; i++) {
            if (i == d) continue;
            maxa = max(a[id][i], maxa), maxb = max(a[b.id][i], maxb);
        }
        return (maxa == maxb ? a[id][d] > a[b.id][b.d] : maxa > maxb);
    }
}; 
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= 3; j++) 
                cin >> a[i][j];
        priority_queue<node> pq1, pq2, pq3;
        for (int i = 1; i <= n; i++) {
            int maxx = -1, maxi = -1;
            for (int j = 1; j <= 3; j++) if (a[i][j] > maxx) maxx = a[i][j], maxi = j;
            if (maxi == 1) pq1.push({maxi, i});
            else if (maxi == 2) pq2.push({maxi, i});
            else pq3.push({maxi, i});
        }
        while (pq1.size() > n / 2) {
            int i = pq1.top().id;
            pq1.pop();
            if (a[i][2] > a[i][3]) pq2.push({2, i});
            else pq3.push({3, i});
        }
        while (pq2.size() > n / 2) {
            int i = pq2.top().id;
            pq2.pop();
            if (a[i][1] > a[i][3]) pq1.push({1, i});
            else pq3.push({3, i});
        }
        while (pq3.size() > n / 2) {
            int i = pq3.top().id;
            pq3.pop();
            if (a[i][2] > a[i][1]) pq2.push({2, i});
            else pq1.push({1, i});
        }
        ll ans = 0;
        while (pq1.size()) {
            ans += a[pq1.top().id][pq1.top().d];
            pq1.pop();
        }
        while (pq2.size()) {
            ans += a[pq2.top().id][pq2.top().d];
            pq2.pop();
        }
        while (pq3.size()) {
            ans += a[pq3.top().id][pq3.top().d];
            pq3.pop();
        }
        cout << ans << endl;
    }
    return 0;
}