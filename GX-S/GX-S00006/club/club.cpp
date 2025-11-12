#include<bits/stdc++.h>
using namespace std;
int bns;
int sum[10050][5];
int n,t;
int MAX=-1;
int dfs(int ans,int a,int b,int c,int m)
{
    if(a>n/2||b>n/2||c>n/2)
    {
        return 0;
    }
    dfs(ans+sum[m+1][1],a+1,b,c,m+1);
    dfs(ans+sum[m+1][2],a,b+1,c,m+1);
    dfs(ans+sum[m+1][3],a,b,c+1,m+1);
    if(m==n)
    {
        MAX=max(MAX,ans);
        return 0;
    }
    return 0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            for(int v=1;v<=3;v++)
            {
                cin>>sum[j][v];
                if(sum[j][v]==0&&v!=1)
                {
                    bns++;
                }
            }
        }
        if(bns==n*2)
        {
            int num[10050];
            for(int i=1;i<=n;i++)
            {
                num[i]=sum[i][1];
            }
            sort(num+1,num+n+1);
            int u=0;
            for(int i=n;i>=n/2;i++)
            {
                u+=num[i];
            }
            cout<<u<<" ";
        }
        else
        {
            dfs(0,0,0,0,0);
            cout<<MAX<<" ";
            MAX=-1;
        }
    }
    return 0;
}
