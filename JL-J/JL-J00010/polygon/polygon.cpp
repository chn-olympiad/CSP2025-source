#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[5005];
long long ans;
void dfs(int step,int mx,int sum,int cnt)
{
    if(step==n+1)
    {
        return ;
    }
    if(sum+a[step]>2*max(mx,a[step])&&cnt>=2)
    {
        ans++;
        ans%=M;
    }
    dfs(step+1,max(mx,a[step]),sum+a[step],cnt+1);
    dfs(step+1,mx,sum,cnt);
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
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=1)
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        for(int i=3;i<=n;i++)
        {
            long long mul=1;
            for(int j=n;j>i;j--)
            {
                mul*=j;
                mul%=M;
            }
            for(int j=1;j<=n-i;j++)
            {
                mul/=j;
            }
            ans+=mul;
            ans%=M;
        }
        cout<<ans<<endl;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans%M<<endl;
    return 0;
}
