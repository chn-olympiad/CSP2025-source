#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define dep(i, a, b) for (int i = (a); i >= (b); i--)
#define il inline
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 5;
ll n, k, a[MAXN], s[MAXN], ans;
vector<pair<int, int>> v;
il void Dfs(int u, ll cnt) {
    if (u == n) {
        ans = max(ans, cnt);
        // cout << endl;
        return ;
    }
    int tmp;
    // if (tmp == k) {cnt++; v.push_back({u, u});}
    rep(i, 1, n) {
        if (u + i - 1 < n) {
            tmp = (s[u + i - 1] ^ s[u - 1]);
            if (u - 1 == 0) tmp = s[u];
        } else {
            tmp = (s[n] ^ s[u - 1]);
            if (u - 1 == 0) tmp = s[u];
        }
        if (tmp == k) {
            cnt++;
            Dfs(u + 1, cnt + 1);
        } else {
            Dfs(u + 1, cnt);
        }
    }
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    rep(i, 1, n) {
        cin >> a[i];
        if (i == 1) s[i] = a[i];
        else s[i] = (s[i - 1] ^ a[i]);
    }
    rep(i, 1, n) {
        Dfs(i, 0);
    }
    cout << ans << endl;
    return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3

s[l~r] = s[r] ^ s[l - 1]
*/
