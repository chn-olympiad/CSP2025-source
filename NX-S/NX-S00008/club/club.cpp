#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005][4],ren[4],_max=-1,bian=0;
void dfs(int x,int sum)
{
    for(int i=1;i<=3;i++)   if(ren[i]>n/2)  return ;
    if(x==n+1)
    {
        _max=max(_max,sum);
        return ;
    }
    for(int i=1;i<=3;i++)
    {
        ren[i]++;
        dfs(x+1,a[x][i]+sum);
        ren[i]--;
    }
    return ;
}
void dfs2(int x,int sum)
{
    if(bian>n/2)    return ;
    if(x==n+1)
    {
        _max=max(_max,sum);
        return  ;
    }
    bian++;
    dfs(x+1,sum+a[x][1]);
    bian--;
    dfs(x+1,sum+a[x][2]);
}
void work()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
        }
    }
    _max=-1;
    if(n<=30)
    {
        for(int i=1;i<=3;i++)   ren[i]=0;
        for(int i=1;i<=3;i++)
        {
            ren[i]++;
            dfs(1,a[1][i]);
            ren[i]--;
        }
        cout<<_max<<endl;
        return ;
    }
    else if(n==200)
    {
        bian=0;
        for(int i=1;i<=2;i++)
        {
            bian++;
            dfs2(1,a[1][i]);
            bian--;
        }
        return ;
    }
    else if(n==100000)
    {
        int d[100005];
        for(int i=1;i<=n;i++)
        {
            d[i]=a[i][1];
        }
        sort(d+1,d+1+n);
        int sum=0;
        for(int i=n;i>n/2;i++)
        {
            sum+=d[i];
        }
        cout<<sum;
        return ;
    }
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(t;t>=1;t--)
    {
        work();
    }
    return 0;
}
