# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 1e5 + 5;
//my last csp s
char s[N];
int c[N];
int p[N];
signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cin >> s + 1;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) p[i] = i;
    int ans = 0;
    do{
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(cnt >= c[p[i]])
            {
                cnt++;
                continue;
            }
            if(s[i] == '0') cnt++;
        }
        if(n - cnt >= m) ans++;
    }while(next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
}
