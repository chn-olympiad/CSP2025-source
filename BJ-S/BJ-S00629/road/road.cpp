#include<iostream>
#include<algorithm>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
using namespace std;
typedef long long ll;
const int mod=1e9+7,maxn=1e4+30,maxk=20,maxm=1e6+5;
inline int read(){
    int res=0,p=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')p=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+(c-'0');
        c=getchar();
    }
    return res*p;
}
int fa[maxn],siz[maxn],ac[maxk];
struct edge{
    int u,v,w;
    inline bool operator<(edge b){
        return w<b.w;
    }
}ae[maxm];
bool vis[maxm],bl[maxn];
inline int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
ll ans=0x3f3f3f3f3f3f3f3f;
inline ll Kruskal(ll res,int m,int n){
    rep(v1,1,n){
        fa[v1]=v1;
        siz[v1]=1;
    }
    rep(v1,1,m)if(!bl[ae[v1].v]){
        int x=find(ae[v1].u),y=find(ae[v1].v);
        if(x!=y){
            if(siz[x]<siz[y])swap(x,y);
            fa[y]=x;
            siz[x]+=siz[y];
            res+=ae[v1].w;
            vis[v1]=true;
        }
        if(res>=ans)return ans;
    }
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int in=read(),im=read(),ik=read(),tt=0;
    rep(v1,1,im){
        scanf("%d %d %d",&ae[v1].u,&ae[v1].v,&ae[v1].w);
    }
    sort(ae+1,ae+im+1);
    ans=Kruskal(0,im,in);
    rep(v1,1,im)if(vis[v1])ae[++tt]=ae[v1];
    rep(v1,1,ik){
        ac[v1]=read();
        rep(v2,1,in){
            ae[++tt]={v2,in+v1,read()};
        }
    }
    sort(ae+1,ae+tt+1);
    rep(v1,1,(1<<ik)-1){
        ll curs=0;
        rep(v2,1,ik){
            if(v1&(1<<v2-1)){
                curs+=ac[v2];
            }
            else bl[v2+in]=true;
        }
        ans=min(ans,Kruskal(curs,tt,in+ik));
        rep(v2,1,ik)bl[v2+in]=false;
    }
    cout<<ans<<endl;
    return 0;
}