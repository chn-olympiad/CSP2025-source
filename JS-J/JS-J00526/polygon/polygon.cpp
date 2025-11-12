#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll m=998244353;
ll f[5005][5005];
ll a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        f[i][a[i]]=1;
    }
    for(int i=2;i<=n-1;i++)
    {
        for(int j=1;j<=5001;j++)
        {
            f[i][j]+=f[i-1][j];
            f[i][min(a[i]+j,(ll)5001)]+=f[i-1][j];
            f[i][j]%=m;
            f[i][min(a[i]+j,(ll)5001)]%=m;
        }
    }
    for(int i=2;i<=n-1;i++)
    {
        for(int j=a[i+1]+1;j<=5005;j++)
        {
            ans+=f[i][j];
            ans%=m;
        }
    }
    cout<<ans;
    return 0;
}
