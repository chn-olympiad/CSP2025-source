#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long  n,m,k,ans,sum,cnt;
struct node{
    long long  u,v,w;
};
bool cmp(node x,node y){
    return x.w<y.w;
}
long long  h[15];
bool vis[15];
bool v[100015];
node g[100015];
long long  fa[100015];
void unite(){
    for(long long  i=1;i<=n+k;i++){
        fa[i]=i;
    }
}
long long  find(long long  x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
//void bing(long long  x,long long  y){
//    x=find(x),y=find(y);
//    fa[x]=fa[y];
//    return ;
//}
//bool same(long long  x,long long  y){
//    return find(x)==find(y);
//}
//bool check(){
//    bool flag=1;
//    for(long long  i=2;i<=n;i++){
//        if(!same(i,i-1)) flag =0;
//    }
//    return flag;
//}
void f(){
    for(long long  i=1;i<=m;i++){
        node to=g[i];
        int x=find(to.v),y=find(to.u);
        if(!x!=y){
            fa[x]=fa[y];
            if(to.v>n&&vis[to.v-n]){
                ans-=h[to.v-n];
            }else if(to.v>n){
                vis[to.v-n]=1;
                cnt++;
            }
            if(to.u>n&&vis[to.u-n]){
                ans-=h[to.u-n];
            }else if(to.u>n){
                vis[to.u-n]=1;
                cnt++;
            }
            ans+=to.w;
            if(!v[to.v]) sum++;
            if(!v[to.u]) sum++;
            v[to.u]=v[to.v]=1;
        }
        if(sum-cnt==n) return;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    unite();
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        g[i]={u,v,w};
    }
    for(long long  i=1;i<=k;i++){
        cin>>h[i];
        for(long long  j=1,v;j<=n;j++){
            cin>>v;
            g[++m]={i+n,j,v+h[i]};
        }
    }
    sort(g+1,g+1+m,cmp);
    f();
    cout<<ans;
    return 0;
}
