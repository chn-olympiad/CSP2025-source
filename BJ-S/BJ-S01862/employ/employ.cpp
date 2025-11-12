#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = l, i##KON = r; i <= i##KON; ++i)
#define per(i, l, r) for(int i = l, i##KON = r; i >= i##KON; --i)
using namespace std;
using ll = long long;
constexpr int N{505}, P{998244353};
int n, m, c[N], cnt[N];
string s;
int p[N];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    s = ' ' + s;
    int ans = 0;
    rep(i, 1, n)
        cin >> c[p[i] = i];
    do
    {
        int x = 0;
        rep(i, 1, n)
            x += s[i] == '0' || x >= c[p[i]];
        ans += n - x >= m;
    }
    while(next_permutation(p + 1, p + n + 1));
    cout << ans << '\n';
    return 0;
}
//freopen
