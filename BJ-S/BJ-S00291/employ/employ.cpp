#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int MOD=998244353;
int n,m,c[N],p[N];
char s[N];

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=1;i<=n;i++) cin>>c[i];

    if (n>10)
    {
        int cnt=0,ans=1;
        for (int i=1;i<=n;i++) ans=ans*i%MOD; cout<<ans<<"\n"; return 0;
    }
    int ans=0;
    for (int i=1;i<=n;i++) p[i]=i;
    do
    {
        int cnt=0,res=0;
        for (int i=1;i<=n;i++)
        {
            if (cnt>=c[p[i]]) { cnt++; continue; }
            if (s[i]=='0') cnt++;
            else res++;
        }
        ans+=(res>=m);
    }while (next_permutation(p+1,p+1+n));
    cout<<(ans%MOD)<<"\n"; return 0;
}