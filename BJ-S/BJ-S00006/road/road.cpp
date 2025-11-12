#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define int long long
using namespace std;
const int N=10005;
const int M=1e6+5;
const int K=12;
int n,m,k;
int co[K];
struct node{
    int num,id;
}ca[K][N];
struct edge{
    int u,v,w;
}e[M];
struct nodeq{
    int u,v,w;
    bool type;
    int vil;
    bool operator <(const nodeq&t)const{
        return w>t.w;
    }
};
int fa[N],sum[N];//bing cha ji
bool used[K];//used k as village
//int ed[K][N];//used k as village, now smallest on i=ed[k][i]
int findfa(int x){
    if(fa[x]==x)return fa[x];
    return fa[x]=findfa(fa[x]);
}
int ans=1e18;
void solve(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        sum[i]=1;
    }
    int ret=0;
    priority_queue<nodeq>q;
    for(int i=1;i<=k;i++){
        if(used[i]){
            ret+=co[i];
            for(int j=1;j<=n;j++){
            //    ed[i][j]=j+1;
                q.push((nodeq){j,j+1,ca[i][j].num+ca[i][j+1].num,true,i});//chuan de bu shi real person
            }
        }
    }
    for(int i=1;i<=m;i++){
        q.push((nodeq){e[i].u,e[i].v,e[i].w,false,0});
    }
    int cnt=1;
    while(cnt<n){
        cnt++;
        while(!q.empty()){
            nodeq u=q.top();
            q.pop();
            int x=u.u,y=u.v,w=u.w,type=u.type,vil=u.vil;
            if(type){
                if(y!=n)
                    q.push((nodeq){x,y+1,ca[vil][x].num+ca[vil][y+1].num,true,vil});
                x=ca[vil][x].id,y=ca[vil][y].id;
            }
            int fx=findfa(x),fy=findfa(y);
            if(fx==fy)continue;
            ret+=w;
            if(sum[fx]<sum[fy]){
                fa[fx]=fy;
                sum[fy]+=sum[fx];
            }else{
                fa[fy]=fx;
                sum[fx]+=sum[fy];
            }
            break;
        }
    }
    ans=min(ans,ret);
    return;
}
void dfs(int x){
    if(x==k+1){
        solve();
        return;
    }
    used[x]=false;
    dfs(x+1);
    used[x]=true;
    dfs(x+1);
    used[x]=false;
}
bool cmp(node x,node y){
    return x.num<y.num;
}
bool cmpe(edge x,edge y){
    return x.w<y.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        e[i].u=u,e[i].v=v,e[i].w=w;
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&co[i]);
        for(int j=1;j<=n;j++){
            int tp;
            scanf("%lld",&tp);
            ca[i][j].num=tp;
            ca[i][j].id=j;
        }
        sort(ca[i]+1,ca[i]+n+1,cmp);
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}
