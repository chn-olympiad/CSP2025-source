#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=1e6+5;
int n,m;
long long k,nw[15][maxn],c[15],fa[maxn+10],s[1025],ans,sum;
struct xxx
{
    int u,v;
	long long w;
    bool operator < (const xxx o) const {return w<o.w;}
    bool operator > (const xxx o) const {return w>o.w;}
}a[maxm];
vector<int> e;
xxx d[1025][maxn+10],f[maxn*2+10];
int fnd(int x)
{
    if(fa[x]!=x)fa[x]=fnd(fa[x]);
    return fa[x];
}
void dfs(long long x,long long y,long long z)
{
    if(x>k)
    {
        if(!z)return;
        int zz=(1<<e.back()-1),sz=e.size();
        sum=0;
        for(int i=1;i<=s[z-zz];i++)f[++sum]=d[z-zz][i];
        for(int i=1;i<=n;i++)f[++sum]={i,n+sz,nw[e.back()][i]};
        for(int i=1;i<=n+sz;i++)fa[i]=i;
        sort(f+1,f+sum+1);
        for(int i=1;i<=sum;i++)
        {
            if(fnd(f[i].u)!=fnd(f[i].v))
            {
                fa[fnd(f[i].u)]=fnd(f[i].v);
                y+=f[i].w;
                d[z][++s[z]]=f[i];
            }
        }
        ans=min(ans,y);
        return;
    }
    dfs(x+1,y,z);
    e.push_back(x);
    dfs(x+1,y+c[x],z+(1<<x-1));
    e.pop_back();
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>nw[i][j];
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(fnd(a[i].u)!=fnd(a[i].v))
        {
            fa[fnd(a[i].u)]=fnd(a[i].v);
            d[0][++s[0]]=a[i];
            ans+=a[i].w;
        }
    }
    dfs(1,0,0);
    cout<<ans;
}
