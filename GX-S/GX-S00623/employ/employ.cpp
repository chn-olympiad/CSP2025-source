#include <bits/stdc++.h>
#define int long long
const int N = 5e2 + 5, mod = 998244353;
using namespace std;

int n, m;
string t;
int c[N];

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin>>n>>m>>t;
    for(int i = 1; i <= n; i ++) cin>>c[i];
    int ans = 1;
    for(int i = 1; i <= n; i ++){
      ans *= i;
      ans %= mod;
    }
    if(s[1] == 0) ans = 0;
    cout<<ans<<"\n";
    return 0;
}
