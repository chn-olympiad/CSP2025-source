#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
};
node edg[1060000];
int fa[2050];
int p=0;
long long ans=0;
int fin(int x){
    if(fa[x]==x) return x;
    fa[x]=fin(fa[x]);
    return fa[x];
}
void memge(int x,int y){
    fa[fin(fa[x])]=fin(fa[y]);
    return;
}
int n,m,k;
bool cmp(node x,node y){
    return x.w<y.w;
}
vector<node> sum;
int cnt[2050];
void kruskar(){

    sort(edg+1,edg+1+p,cmp);

    for(int i=1;i<=p;i++){
        long long u=edg[i].u,v=edg[i].v;
        if(u>v) swap(u,v);
        if(fin(u)!=fin(v)) {

            sum.push_back(edg[i]);
            memge(u,v);
        }
    }
    for(auto i:sum){
        cnt[i.u]++,cnt[i.v]++;
    }
    //for(int i=1;i<=10;i++) cout<<cnt[i]<<' ';
    for(auto i:sum){
        if(i.u>m){
            if(cnt[i.u]==1) {
                    continue;
            }
        }
        if(i.v>m){
            if(cnt[i.v]==1) {
                    continue;
            }
        }
        ans+=i.w;
    }
    return ;
}
void init(){
    for(int i=1;i<=2049;i++) fa[i]=i;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=m;i++){
        node f;
        cin>>f.u>>f.v>>f.w;
        if(f.u>f.v) swap(f.u,f.v);
        edg[++p]=f;
    }

    for(int i=m+1,c;i<=k+m;i++){
        cin>>c;
        for(int j=1;j<=n;j++) {
            node f;
            cin>>f.w;
            f.u=n+i-m;f.v=j;
            if(f.u>f.v) swap(f.u,f.v);
            edg[++p]=f;
        }
    }/*
    for(int i=1;i<=20;i++) cout<<fa[i]<<' ';
    cout<<endl;*/
    kruskar();
    /*
    for(auto i:sum){
        cout<<i.u<<' '<<i.v<<' '<<i.w<<' ';
        cout<<'\n';
    }*/
    cout<<ans<<'\n';
    return 0;
}
