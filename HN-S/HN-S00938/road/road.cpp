#include<bits/stdc++.h>
#define int long long 
using namespace std;
int tot,ans,n,m,k;
struct node
{
    int x,y,w;
}a[1000005],b[1000005],cc[1000005];
int s[15][10005];
int c[10005];
namespace DSU
{
    int f[1000005*2];
    int find(int x)
    {
        if(f[x]==x) return x;
        return f[x]=find(f[x]);
    }
    void merge(int x,int y)
    {
        int a=find(x),b=find(y);
        if(a==b) return ;
        f[a]=b;
    }
}
int cmp(node x,node y)
{
    return x.w<y.w;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++) DSU::f[i]=i;
    for(int i=1;i<=m;i++)
        cin>>a[i].x>>a[i].y>>a[i].w;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>s[i][j];
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int aa=DSU::find(a[i].x),bb=DSU::find(a[i].y);
        if(aa==bb) continue;
        DSU::merge(aa,bb);
        ans+=a[i].w;b[++tot]=a[i];cc[tot]=b[tot];
    }
    for(int i=0;i<(1<<k);i++)
    {
        int now=0,siz=tot;
        for(int j=1;j<=n+k;j++) DSU::f[j]=j;
        for(int j=1;j<=k;j++)
        {
            if(!((i>>(j-1))&1)) continue;
            now+=c[j];
            if(now>=ans) break;
            for(int l=1;l<=n;l++)
            {
                if(s[j][l]>=b[tot].w) continue;
                b[++siz]=((node){n+j,l,s[j][l]});
            }
        }
        if(now>=ans) continue;
        sort(b+1,b+siz+1,cmp);
        for(int j=1;j<=siz;j++)
        {
            int aa=DSU::find(b[j].x),bb=DSU::find(b[j].y);
            if(aa==bb) continue;
            DSU::merge(aa,bb);
            now+=b[j].w;
            if(now>=ans) break;
        }
        for(int j=1;j<=tot;j++) b[j]=cc[j];
        ans=min(ans,now);
    }
    cout<<ans;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/