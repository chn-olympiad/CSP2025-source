#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> hk;
int n,k;
vector<int> hq;
vector<int> dp;
vector<bool> vis;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    hk.resize(n+1);
    hq.resize(n+1);
    dp.resize(n+1);
    vis.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        hq[i]=-1;
        dp[i]=0;
        vis[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        bool yes=false;
        hk[i]=temp;
        if(temp==k)
        {
            vis[i]=true;
            hq[i]=i;
            yes=true;
        }
        for(int j=i-1;j>=1;j--)
        {
            if(vis[j]==true)
            {
                continue;
            }
            hk[j]=hk[j]^temp;
            if(hk[j]==k&&yes==false)
            {
                hq[i]=j;
                yes=true;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(hq[i]==-1)
        {
            dp[i]=dp[i-1];
            continue;
        }
        dp[i]=dp[i-1];
        dp[i]=max(dp[i],dp[hq[i]-1]+1);
    }
    cout<<dp[n];
    return 0;
}
