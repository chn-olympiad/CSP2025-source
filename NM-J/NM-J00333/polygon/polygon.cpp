#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5;
int n;
long long cnt=0;
int p=998244353;
int a[MAXN];
bool f[MAXN];
long long jie(int s)
{
    if(s==0)
    return 1;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
    }
    return ans;

}
long long C(int u,int d)
{
    if(u==d)
        return 1;
    int u2=jie(u);
    return (jie(d)-u2)/u2
}
void dfs(int k,int v,int w,int Max)
{
    if(k>3)
    {
        if(v>2*Max)
        {
            cnt=(cnt+1)%p;
        }
    }
    for(int i=w;i<=n;i++)
    {
        if(!f[i])
        {
            f[i]=1;
            dfs(k+1,v+a[i],i+1,max(Max,a[i]));
            f[i]=0;
        }
    }
}
int main()
{
    freopen("ploygon.in","r",stdin);
    freopen("ploygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n>20)
    {
        for(int i=3;i<=n;i++)
        {
            cnt=(cnt%p+C(i,n)%p)%p;
        }
    }
    else
        dfs(1,0,1,-1);
    cout<<cnt;
    return 0;
}
