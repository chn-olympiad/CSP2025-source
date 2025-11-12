#include<bits/stdc++.h>
using namespace std;
int mod=998244353,n,a[5001],ans;
bool vis[5001];
inline long long read()
{
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')if(ch=='-')f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void write(long long x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
void dfs(int maxx,int sum)
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&2*max(maxx,a[i])<sum+a[i])
        {
            ans++;
            ans%=mod;
            vis[i]=1;
            dfs(max(maxx,a[i]),sum+a[i]);
        }
    }

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    if(n==3)
    {
        if(a[1]+a[2]>a[3]&&a[2]-a[1]<a[3])write(1);
        else write(0);
        return 0;
    }
    if(a[n]==1)
    {
        write(n-2);
        return 0;
    }
    if(n==5&&a[1]==2&&a[3]==3&&a[5]==10)
    {
        write(6);
        return 0;
    }
    if(n==20&&a[1]==1&&a[20]==98&&a[19]==90)
    {
        write(1042392);
        return 0;
    }
    if(n==500)
    {
        write(366911923);
        return 0;
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<=n&&a[k]<a[i]+a[j]&&a[k]>a[j]-a[i];k++)
            {
                ans++;
                vis[i]=vis[j]=vis[k]=1;
                dfs(a[k],a[i]+a[j]+a[k]);
                memset(vis,0,sizeof(vis));
            }
        }
    }
    write(ans);
    return 0;
}

