#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge
{
    int x,y;
    ll z;
};
edge e[2000111];
int fa[10111],n,m,k;
ll c[10011];
ll ans;
ll a[11][10111];
inline int fy(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=fy(fa[x]);
}
inline void uni(int x,int y)
{
    fa[fy(x)]=fy(y);
}
inline bool cmp(edge p,edge q)
{
    return p.z<q.z;
}
inline ll kruskal(int len,int node)
{
    int cnt=0;
    ll sum=0;
    for(int i=1;i<=len;i++)//Kruskal
    {
        int xx=fy(e[i].x),yy=fy(e[i].y);
        if(xx!=yy)
        {
            uni(xx,yy);
            sum+=e[i].z,cnt++;
            if(cnt==node-1) break;
        }
    }
    return sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
        scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].z);
    sort(e+1,e+m+1,cmp);
    ans=kruskal(m,n);
    if(k>0)
    {
        for(int i=1;i<=k;i++)
        {
            scanf("%lld",&c[i]);
            for(int j=1;j<=n;j++)
                scanf("%lld",&a[i][j]);
        }
        int p=1,q=(1<<k);//zip
        while(p<q)
        {
            int cnt=0,tmp=0,add=0;
            for(int i=1;i<=n+k;i++) fa[i]=i;
            for(int i=1;i<=k;i++)
            {
                if((1<<i-1)&p)
                {
                    ++cnt,add+=c[i];
                    for(int j=1;j<=n;j++)
                        ++tmp,e[m+tmp].x=n+cnt,e[m+tmp].y=j,e[m+tmp].z=a[i][j];
                }
            }
            sort(e+1,e+m+tmp+1,cmp);
            ll num=kruskal(m+tmp,n+cnt);
            ans=min(ans,num+add);
            p=p<<1;
        }
    }
    printf("%lld",ans);
	return 0;
}
