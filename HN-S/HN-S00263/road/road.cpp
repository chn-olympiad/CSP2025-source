#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<='0') {if(ch=='-') f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0') {x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
    return x*f;
}
const int N=1e4+5,M=1e6+5,K=15;
int fa[N],n,m,k,c[K],cnt[K],ans=0x3fffffffffffffff;
bool vis[K];
struct stu{
    int u,v,w;
    bool operator<(const stu &t) const{
        return w<t.w;
    }
}a[M],b[K][N];
struct node{
    int num,id;
    bool operator<(const node &t) const{
        return num>t.num;
    }
};
int find(int x){if(x==fa[x]) return x;return fa[x]=find(fa[x]);}
int val(int cnttt){
    int x=1-cnttt,res=0;memset(cnt,0,sizeof(cnt));int cntt=0;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    priority_queue<node> q;
    for(int i=1;i<=k;i++) if(vis[i]) q.push((node){b[i][++cnt[i]].w,i});
    q.push((node){a[++cntt].w,0});
    // printf("114514\n");
    while(!q.empty()){
        node h=q.top();q.pop();
        int num=h.num,id=h.id;
        if(id==0){
            int u=a[cntt].u,v=a[cntt].v;
            u=find(u),v=find(v);
            if(u^v) {
                // printf("1:%lld %lld %lld %lld\n",u,v,num,res+num);
                res+=num,x++;if(x==n){return res;}fa[u]=v;
            }
            if(++cntt<=m) q.push((node){a[cntt].w,0});
        }
        else{
            int u=b[id][cnt[id]].u+n,v=b[id][cnt[id]].v;
            u=find(u),v=find(v);
            if(u^v) {
                // printf("2:%lld %lld %lld %lld\n",u,v,num,res+num);
                res+=num,x++;if(x==n){return res;}fa[u]=v;
            }
            if(++cnt[u]<=n) q.push((node){b[u][cnt[u]].w,u});
        }
        if(res>=ans)return ans;
    }
    return ans;
}
signed main(){
    freopen("road.in" ,"r",stdin );
    freopen("road.out","w",stdout);
    // freopen("1.in","r",stdin);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++) {
        int u=read(),v=read(),w=read();a[i]=(stu){u,v,w};
    }
    sort(a+1,a+m+1);
    // for(int i=1;i<=m;i++) printf("%lld %lld %lld\n",a[i].u,a[i].v,a[i].w);
    for(int i=1;i<=k;i++) {c[i]=read();for(int j=1;j<=n;j++) b[i][j]=(stu){i,j,read()};}
    for(int i=1;i<=k;i++) sort(b[i]+1,b[i]+n+1);
    // for(int i=1;i<=k;i++) {for(int j=1;j<=n;j++) printf("%lld ",b[i][j].w);printf("\n");}
    int len=1<<k,ans=0x7fffffff;
    for(int l=0;l<len;l++) {
        memset(vis,0,sizeof(vis));
        int cnt=0,res=0;
        for(int i=1;i<=k;i++) if(l&(1<<(i-1))) {cnt++,vis[i]=1;res+=c[i];}
        ans=min(ans,res+val(cnt));
        // printf("%lld\n",ans);
    }
    printf("%lld",ans);
    return 0;
}