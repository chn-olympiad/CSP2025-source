#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e5 + 5;
int t, n, a[N][3], ord[N][3];
inline void Solve() {
    cin >> n;
    vector <pair<int, int> > bst;
    for (int i = 1;i <= n;i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        vector <pair<int, int> >lis;
        lis.push_back({ a[i][0],0 });
        lis.push_back({ a[i][1],1 });
        lis.push_back({ a[i][2],2 });
        sort(lis.begin(), lis.end(), greater<pair<int, int> >());
        for (int j = 0;j < 3;j++)
            ord[i][j] = lis[j].second;
        bst.push_back({ a[i][ord[i][0]],i });
    }
    sort(bst.begin(), bst.end(), greater<pair<int, int> >());
    multiset <int> st[3];
    int ans = 0;
    for (auto it : bst) {
        int i = it.se;
        int p = ord[i][0];
        int pp = ord[i][1];
        if (st[p].size() == n / 2) {
            if (a[i][p] - a[i][pp] > *st[p].begin()) {
                ans -= *st[p].begin();
                ans += a[i][p];
                st[p].erase(st[p].begin());
                st[p].insert(a[i][p] - a[i][pp]);
            }
            else
                ans += a[i][pp];
        }
        else {
            ans += a[i][p];
            st[p].insert(a[i][p] - a[i][pp]);
        }
    }
    cout << ans << "\n";
    //cerr << st[0].size() << " " << st[1].size() << " " << st[2].size() << " " << n / 2 << "\n";
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
        Solve();
    return 0;
}