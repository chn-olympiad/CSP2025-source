#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k;
struct town{
    int cost,con[10005];
}c[15];
struct edge{
    int u,v,w;
}a[1000005];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
struct node{
    int next,w;
    bool fix;
};
bool A=1;
vector<node> g[10005];
int fa[10005];
void chushihua(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    return ;
}
int finds(int x){
    if(fa[x]==x) return x;
    return fa[x]=finds(fa[x]);
}
void unite(int x,int y){
    x=finds(x),y=finds(y);
    if(x==y) return;
    fa[x]=y;
    return ;
}
bool same(int x,int y){
    return finds(x)==finds(y);
}
void kekosika(){ //board but not bored(truth is I forgettt
    chushihua();
    long long sum=0;
    int cnt=0;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=m;i++){
        if(!same(a[i].u,a[i].v)){
            sum+=a[i].w;
            cnt++;
            unite(a[i].u,a[i].v);
        }
        if(cnt==n-1) break;
    }
    cout<<sum;//maybe i right
    return ;
}
int main(){
    freopen("road3.in","r",stdin);
    freopen("road3.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
        g[a[i].u].push_back({a[i].v,a[i].w,0});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i].cost;
        if(c[i].cost!=0) A=0;//how can i do this dream
        for(int j=1;j<=n;j++){
            scanf("%d",&c[i].con[j]);
        }
    }
    if(k==0){//sad board(the 1st word
        kekosika();
    }//powerless become my failure
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
