#include <bits/stdc++.h>

using namespace std;
const int mod=998244353;
int n,used[5004],ans,maxn,a[5003],sum,t;
int summ[5004];
void dfs(int t,int i)
{
    if(t>=3&&sum>maxn*2)
    {
        ans=(ans+1)%mod;
    }
    if(maxn*2>=sum+summ[n]-summ[i])return;
    for(int j=i+1;j<=n;j++)
    {
        if(!used[j])
        {
            int cnt=maxn;
            maxn=max(maxn,a[j]);
            used[j]=1;
            sum+=a[j];
            dfs(t+1,j);
            maxn=cnt;
            used[j]=0;
            sum-=a[j];
    }
    }
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++)summ[i]=summ[i-1]+a[i];
    dfs(1,0);
    cout<<ans;
    return 0;
}

