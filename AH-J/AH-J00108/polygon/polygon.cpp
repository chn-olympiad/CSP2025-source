#include<bits/stdc++.h>
using namespace std;
int n,a[5002],dp[5002][5002],flag[5002],sum,ans,s[5002];
void dfs(int st,int tot,int len,int maxx)
{
    if(tot>=3&&len>2*maxx)sum=(sum+1)%998244353;
    for(int i=st+1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            len+=a[i];
            flag[i]=1;
            tot++;
            maxx=a[i];
            dfs(i,tot,len,maxx);
            len-=a[i];
            flag[i]=0;
            tot--;
            maxx=0;
        }
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-2;i++)
    {
        sum=0;
        dfs(i,1,a[i],a[i]);
        sum%=998244353;
        ans=(ans+sum)%998244353;
    }
    cout<<ans;
    return 0;
}
