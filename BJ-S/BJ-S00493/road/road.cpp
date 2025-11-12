#include<bits/stdc++.h>
using namespace std;
const int N=10010;
struct Edge{
    int x,y,w,id;
}edge[N*200];
bool cmp(Edge a1,Edge a2){
    return a1.w<a2.w;
}
int a[11][N],c[11],vis[12];
int fa[N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve(){
    int n,m,k;cin>>n>>m>>k;
    int A=1;
    for(int i=1;i<=m;i++){
        cin>>edge[i].x>>edge[i].y>>edge[i].w;edge[i].id=0;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0) A=0;
        int pos=0;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0) pos=j;
        }
        if(!pos) A=0;
    }
    if(A){
        int cnt=m;
        for(int i=1;i<=k;i++){
            int pos=0;
            for(int j=1;j<=n;j++)
                if(a[i][j]==0) pos=j;
            for(int j=1;j<=n;j++)
                if(j!=pos){
                    edge[++cnt].x=j,edge[cnt].y=pos,edge[cnt].w=a[i][j];
                }
        }
        long long ans=0,num=0;
        for(int i=1;i<=n;i++) fa[i]=i;
        sort(edge+1,edge+cnt+1,cmp);
        for(int i=1;i<=cnt&&num<n-1;i++){
            int x=edge[i].x,y=edge[i].y,w=edge[i].w;
            int fx=find(x),fy=find(y);
            if(fx==fy) continue;
            fa[fy]=fx;ans+=w;num++;
        }
        cout<<ans<<'\n';
        return ;
    }
    int cnt=m;
    for(int i=1;i<=k;i++){
        int pos=0;
        for(int j=1;j<=n;j++)
            if(!pos||a[i][j]<a[i][pos]) pos=j;
        //cout<<pos<<'\n';
        for(int j=1;j<=n;j++)
            if(j!=pos){
                edge[++cnt].x=j,edge[cnt].y=pos,edge[cnt].w=a[i][j]+c[i]+a[i][pos],edge[cnt].id=i;
            }
    }
    long long res=0,num=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m&&num<n-1;i++){
        int x=edge[i].x,y=edge[i].y,w=edge[i].w;
        int fx=find(x),fy=find(y);
        if(fx==fy) continue;
        fa[fy]=fx;res+=w;num++;
    }
    long long ans=0;num=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(edge+1,edge+cnt+1,cmp);
    for(int i=1;i<=cnt&&num<n-1;i++){
        int x=edge[i].x,y=edge[i].y,w=edge[i].w;
        int fx=find(x),fy=find(y);
        if(fx==fy) continue;
        //cout<<w<<' '<<edge[i].id<<' ';;
        if(vis[edge[i].id]) w-=c[edge[i].id]; 
        if(edge[i].id) vis[edge[i].id]=1;
        //cout<<w<<'\n';
        fa[fy]=fx;ans+=w;num++;
        //cout<<ans<<" ";
    }
    //cout<<num<<'\n';
    //cout<<res<<" "<<ans<<'\n';
    cout<<min(ans,res)<<'\n';
    return ;
}
signed main(){
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;T=1;
    while(T--) solve();
}