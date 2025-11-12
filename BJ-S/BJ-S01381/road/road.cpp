#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
struct edge{
    int x,y,w;
};
edge g[N];
int n,m,k,c[15],a[15][N],fa[N],tot,org[N][5],arr[20],ans=1e18;
void add(int x,int y,int w){
    g[++tot].x=x;
    g[tot].y=y;
    g[tot].w=w;
}
void init(){
    for(int i=1;i<=n+20;i++) fa[i]=i;
}
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x),y=find(y);
    fa[y]=x;
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int kruskal(int node_num){
    int cnt=0,now=0;
    sort(g+1,g+tot+1,cmp);
    for(int i=1;i<=tot;i++){
        int x=g[i].x,y=g[i].y;
        if(find(x)!=find(y)){
            cnt+=g[i].w;
            now++;
            if(now==node_num-1){
                return cnt;
            }
            merge(x,y);
        }
    }
}//kruskal correct
void dfs(int now,int now_ans){
    if(now_ans>=ans) return;
    if(now==k){
        init();
        int node_cnt=n;
        tot=0;
        for(int i=1;i<=k;i++){
            if(arr[i]){
                node_cnt++;
                for(int j=1;j<=n;j++){
                    add(n+i,j,a[i][j]);
                }
            }
        }
        for(int i=1;i<=m;i++) add(org[i][1],org[i][2],org[i][3]);
        now_ans+=kruskal(node_cnt);
        ans=min(ans,now_ans);
        return;
    }
    now++;
    arr[now]=0;
    dfs(now,now_ans);
    arr[now]=1;
    dfs(now,now_ans+c[now]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>org[i][1]>>org[i][2]>>org[i][3];
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    init();
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}
