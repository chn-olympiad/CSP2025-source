#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = l, i##KON = r; i <= i##KON; ++i)
using namespace std;
using ll = long long;
constexpr int N{100005};
int T, n, cnt[3], id[N], ad[N];
ll a[N][3];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T--;)
    {
        cin >> n;
        cnt[0] = cnt[1] = cnt[2] = 0;
        ll ans = 0;
        rep(i, 1, n)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            id[i] = 0;
            rep(j, 0, 2) if(a[i][j] > a[i][id[i]])
                id[i] = j;
            ++cnt[id[i]];
            ans += a[i][id[i]];
        }
        int k = -1;
        rep(j, 0, 2) if(cnt[j] > n / 2)
            k = j;
        if(k != -1)
        {
            int tt = 0;
            rep(i, 1, n) if(id[i] == k)
            {
                int pre = a[i][k];
                a[i][k] = 0;
                ad[++tt] = min({pre - a[i][0], pre - a[i][1], pre - a[i][2]});
            }
            sort(ad + 1, ad + tt + 1);
            rep(i, 1, cnt[k] - n / 2)
                ans -= ad[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
//freopen
