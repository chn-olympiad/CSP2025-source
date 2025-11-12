#include<bits/stdc++.h>
using namespace std;
int n,k,a[5011],ans=0,dp[5011][5011];
bool vis[5011];
int yihuohe(int x,int y)
{
    char b[51],c[51],d[51];
    int bf=0,cf=0,flag=0;
    while(x>0)
    {
        bf++;
        b[bf]=x%2;
        x=x/2;
    }
    while(y>0)
    {
        cf++;
        c[cf]=y%2;
        y=y/2;
    }
    int i=1;
    while(bf>=i&&cf>=i)
    {
        if(b[i]==c[i])
        {
            d[i]='0';
        }
        else
        {
            d[i]='1';
        }
        i++;
    }
    while(bf>=i)
    {
        d[i]=b[i];
        i++;
    }
    while(cf>=i)
    {
        d[i]=c[i];
        i++;
    }
    i--;
    for(int j=0;j<i;j++)
    {
        if(d[j+1]=='1')
        {
            flag+=pow(2,j);
        }
    }
    return flag;
}
bool panchong(int j,int i)
{
    for(int s=j;s<j+i;s++)
    {
        if(vis[s]==false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][1]=a[i];
        vis[i]=true;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=2;j<=n-i+1;j++)
        {
            dp[i][j]=yihuohe(dp[i][j-1],a[j+i-1]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            if(dp[j][i]==k&&panchong(j,i)==true)
            {
                ans++;
                for(int s=j;s<j+i;s++)
                {
                    vis[s]=false;
                }
                cout<<j<<" "<<i<<endl;
            }
        }
    }
    cout<<ans;
    return 0;
}
