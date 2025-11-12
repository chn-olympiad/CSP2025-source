#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=510;
int n,m,zero=0;
string s;
int c[N];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)if(s[i]=='0')zero++;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(zero==0)
    {
        int ans=1;
        for(int i=2;i<=n;i++)
        {
            ans*=i;
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
