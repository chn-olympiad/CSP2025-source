#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define ll long long
#define rll register long long
#define INF 1000000000
inline int read(){
    rint x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

int n,m,k,x,y,z,c[15],full,fa[10015],sz[10015],pos[15];
ll res;
pair<int,int>a[15][10005];
struct edge{
    int x,y,z;
}e[1000005];
inline bool cmp(edge x,edge y){
    return x.z<y.z;
}
inline int find(rint x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(rint i=1;i<=m;i++){
        x=read(),y=read(),z=read();
        e[i]={x,y,z};
    }
    sort(e+1,e+1+m,cmp);
    for(rint i=1;i<=n;i++)fa[i]=i,sz[i]=1;
    rint cnt=0;
    for(rint i=1;i<=m;i++){
        x=e[i].x,y=e[i].y,z=e[i].z;
        rint u=find(x),v=find(y);
        if(u==v)continue;
        if(sz[u]>sz[v])swap(u,v);
        fa[u]=v,res+=z;
        e[++cnt]={x,y,z};
        if(cnt==n-1)break;
    }
    for(rint i=1;i<=k;i++){
        c[i]=read();
        for(rint j=1;j<=n;j++)a[i][j].first=read(),a[i][j].second=j;
        sort(a[i]+1,a[i]+1+n);
    }
    full=(1<<k)-1;
    for(rint i=1;i<=full;i++){
        rint s=0;
        rll ans=0;
        for(rint j=1;j<=k;j++){
            if((i>>j-1)&1^1)continue;
            s++,pos[j]=1,ans+=c[j];
        }
        pos[k+1]=1;
        for(rint j=1;j<=n+k;j++)fa[j]=j,sz[j]=1;
        for(rint cnt=1;cnt<n+s;cnt++){
            rint u=0,v=0,w=INF,id=0;
            for(rint j=1;j<=k;j++){
                if((i>>j-1)&1^1)continue;
                x=find(n+j);
                while(pos[j]<=n){
                    y=find(a[j][pos[j]].second),z=a[j][pos[j]].first;
                    if(x==y){
                        pos[j]++;
                        continue;
                    }
                    if(z<w)u=x,v=y,w=z,id=j;
                    break;
                }
            }
            while(pos[k+1]<n){
                x=find(e[pos[k+1]].x),y=find(e[pos[k+1]].y),z=e[pos[k+1]].z;
                if(x==y){
                    pos[k+1]++;
                    continue;
                }
                if(z<w)u=x,v=y,w=z,id=k+1;
                break;
            }
            pos[id]++;
            if(sz[u]>sz[v])swap(u,v);
            fa[u]=v,ans+=w;
        }
        res=min(res,ans);
    }
    printf("%lld\n",res);
    return 0;
}