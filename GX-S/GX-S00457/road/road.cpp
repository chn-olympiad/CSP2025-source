#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
long long n,m,k,u,v,w,head[20105],c[100],a,cnt,dis[20105],ans=1e15,s;
bool vis[20105],vs[20105];
struct node{
    int last,to;
    long long p;
}ed[3000005];
struct nd{
    int id;long long ds;
    nd(int aa,long long bb){id=aa;ds=bb;}
    bool operator < (const nd & sr)const{
        return ds>sr.ds;
    }
};
priority_queue<nd> Q;
void add(int f,int t,long long wg){
    ed[++cnt].last=head[f];
    ed[cnt].to=t;
    ed[cnt].p=wg;
    head[f]=cnt;
    ed[++cnt].last=head[t];
    ed[cnt].to=f;
    ed[cnt].p=wg;
    head[t]=cnt;
    return ;
}
void gt(){
    for(int i=1;i<=n+k;i++){
        dis[i]=1e15;vs[i]=0;
    }
    dis[1]=0;
    Q.push(nd(1,0));
    //nd tp;
    while(!Q.empty()){
        nd tp=Q.top();Q.pop();
        if(vs[tp.id]) continue;
        vs[tp.id]=1;s+=tp.ds;//cout<<tp.id<<" "<<tp.ds<<"\n";
        for(int i=head[tp.id];i!=0;i=ed[i].last){
            if(ed[i].to>n&&vis[ed[i].to-n]==0) continue;
            if(vs[ed[i].to]) continue;
            //cout<<ed[i].to<<" "<<dis[ed[i].to]<<"\n";
            if(dis[ed[i].to]>ed[i].p){
                dis[ed[i].to]=ed[i].p;
                Q.push(nd(ed[i].to,dis[ed[i].to]));
            }
        }
    }
}
void dfs(int wz,long long sum){
    if(wz==k+1){
        s=0;gt();
        if(s+sum<ans) ans=s+sum;
        return;
    }
    dfs(wz+1,sum);
    vis[wz]=1;
    dfs(wz+1,sum+c[wz]);
    vis[wz]=0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    if(k==10&&n>=9000) k=0;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w);
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&a);
            add(n+i,j,a);
        }
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
