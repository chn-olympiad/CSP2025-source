#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100007;
int n;
ll k,a[N];
bool f=1;
int dp[500007][300];
int dfs(int dep,int sum)
{
    if(!dp[dep][sum])
    {
        return dp[dep][sum];
    }
    if(dep>n)
    {
        if(sum==k)
        {
            dp[dep][sum]=1;
            return 1;
        }
        else
        {
            dp[dep][sum]=0;
            return 0;
        }
    }
    if(sum==0)
    {
        dp[dep][sum]=dfs(dep+1,sum^a[dep]);
        return dfs(dep+1,sum^a[dep]);
    }
    else if(sum^a[dep]==k)
    {
        dp[dep][sum]=dfs(dep,0)+(sum==k)*1;
        return dfs(dep,0)+(sum==k)*1;
    }
    else
    {
        dp[dep][sum]=max(dfs(dep+1,sum^a[dep]),dfs(dep,0)+(sum==k)*1);
    }
    return dp[dep][sum];
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if((a[i]!=1)&&(a[i]!=0))
        {
            f=0;
        }
    }
    if(f==1)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=a[i];
        }
        cout<<ans/k;
    }
    else
    {
        cout<<dfs(1,0);
    }
    return 0;
}
