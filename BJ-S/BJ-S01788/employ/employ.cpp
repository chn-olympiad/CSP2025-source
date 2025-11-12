#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[510],sum[510],mod = 998244353;
string s;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    int tmp = n;
    for(int i = 1;i <= tmp;i++) cin >> a[i],n -= a[i] == 0,sum[i] = sum[i - 1] + (a[i] == 0);
    if(m > n) { cout << 0 << endl; return 0; }
    for(int i = 0;i < n;i++) if(s[i] != '1') { cout << 0 << endl; return 0; }
    for(int i = 1;i <= n;i++) if(sum[i] >= a[i])
    {
        n -= 1;
        for(int j = i + 1;j <= n;j++) sum[j] += 1;
    }
    if(m > n) { cout << 0 << endl; return 0; }
    int ans = 1;
    while(n) (ans *= n) %= mod,n -= 1;
    cout << ans << endl;
    return 0;
}
