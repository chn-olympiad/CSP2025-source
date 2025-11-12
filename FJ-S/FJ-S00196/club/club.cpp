#include<bits/stdc++.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i ++)
#define per(i, s, t) for(int i = (s); i >= (t); i --)
using namespace std;
template<typename T>
inline void chmin(T& x, T y) { x = min(x, y); }
template<typename T>
inline void chmax(T& x, T y) { x = max(x, y); }
typedef long long ll;

const int N = 1e5 + 5;
int n, a[N][3], id[N];

void solve()
{
    cin >> n;
    rep(i, 1, n) rep(j, 0, 2) cin >> a[i][j];
    int cnt[3] = {};
    ll ans = 0;
    rep(i, 1, n)
    {
        int mx = max_element(a[i], a[i] + 3) - a[i];
        cnt[mx] ++;
        id[i] = mx;
        ans += a[i][mx];
    }
    rep(i, 0, 2) if(cnt[i] * 2 > n)
    {
        vector<int> dt;
        rep(j, 1, n) if(id[j] == i)
        {
            int mx2 = 0;
            rep(k, 0, 2) if(k != i) chmax(mx2, a[j][k]);
            dt.push_back(a[j][i] - mx2);
        }
        sort(dt.begin(), dt.end());
        int d = cnt[i] - n / 2;
        rep(j, 0, d - 1)
            ans -= dt[j];
        break;
    }
    cout << ans << "\n";
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t; while(t --) solve();

    return 0;
}