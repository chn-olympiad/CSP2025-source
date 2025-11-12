#include <bits/stdc++.h>
using namespace std;
int n;
const int mod=998244353;
int a[505];
int act1(int tot,int max_,int len,int dep)
{
    if(dep>=n)
    {
        if(tot>max_*2&&len>=3) return 1;
        else return 0;
    }
    else
    {
        int ans=act1(tot,max_,len,n+1);
        for(int i=dep+1;i<=n;i++)
            ans=(ans+act1(tot+a[i],max(max_,a[i]),len+1,i)%mod)%mod;
        return ans;
    }
}
int act2()
{
    int ans=0;
    int tot=n*(n-1);
    int div=2;
    for(int i=3;i<=n;i++)
    {
        tot=(n-i+1)*tot%mod;
        div=i*div%mod;
        ans=(ans+tot/div%mod)%mod;
    }
    return ans;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=2) cout<<0;
    else if(n<=20) cout<<act1(0,0,0,0);
    else cout<<act2();
    return 0;
}