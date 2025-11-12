#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+20;
const int M=1.1e6+10;
const int INF=1.14514e18;
int read()
{
    int w=1,s=0;
    char ch=getchar();
    while(ch<'0'||'9'<ch)
    {
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*w;
}
int n,nn,m,mm,k;
struct node
{
    int u,v,w;
}a[M],c[M];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int b[11][N],fa[N],w[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int calc()
{
    sort(c+1,c+1+mm,cmp);
    for(int i=1;i<=nn;i++) fa[i]=i;
    int ans=0,cnt=n;
    for(int i=1;i<=mm;i++)
    {
        int fu=find(c[i].u),fv=find(c[i].v);
        if(fu==fv) continue;
        fa[fv]=fu;
        ans+=c[i].w;
        cnt++;
        if(cnt==nn-1) break;
    }
    return ans;
}
void solve1()
{
    mm=0,nn=n;
    for(int j=1;j<=m;j++) c[++mm]=a[j];
    for(int j=1;j<=k;j++)
    {
        int id=-1,mn=INF;
        for(int z=1;z<=n;z++)
        {
            if(b[j][z]==0) id=z;
        }
        for(int z=1;z<=n;z++) c[++mm]={id,z,b[j][z]};
    }
    cout<<calc();
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++) a[i]={read(),read(),read()};
    bool ok=1;
    for(int i=1;i<=k;i++)
    {
        w[i]=read();
        ok&=(w[i]==0);
        for(int j=1;j<=n;j++) b[i][j]=read();
    }
    if(ok)
    {
        solve1();
        return 0;
    }
    int ans=INF;
    for(int i=0;i<(1<<k);i++)
    {
        int res=0,tot=0;
        mm=0,nn=n;
        for(int j=1;j<=m;j++) c[++mm]=a[j];
        for(int j=1;j<=k;j++)
        {
            if((i>>(j-1))&1)
            {
                nn++;
                res+=w[j];
                for(int z=1;z<=n;z++) c[++mm]={nn,z,b[j][z]};
            }
        }
        ans=min(ans,res+calc());
    }
    cout<<ans<<"\n";
}
