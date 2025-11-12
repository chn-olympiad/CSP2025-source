#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e4+5+10;const int M=1e6+5+N*10;
struct edge{
    int a,b,w;
}yu[M];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
struct bcj{
    int fa[N],sz[N];
    void init(){
        for(int i=0;i<N;i++){
            sz[i]=1;
            fa[i]=0;
        }
    }
    int f(int x){
        if(fa[x])return fa[x]=f(fa[x]);
        return x;
    }
    void merge(int x,int y){
        x=f(x),y=f(y);
        if(x==y)return;
        if(sz[x]>sz[y])swap(x,y);
        fa[x]=y;
        sz[y]+=x;
    }
    bool is_(int x,int y){
        return f(x)==f(y);
    }
};
struct zxscs{
    int n,m,ne;edge e[M];
    bcj t;
    void init(){
        n=0;m=0;
        t.init();
        for(int i=0;i<M;i++){
            e[i]={0,0,0};
        }
    }
    int sum(){
        int ans=0,sm=0;
        for(int i=1;i<=m;i++){
            if(!t.is_(e[i].a,e[i].b)){
                t.merge(e[i].a,e[i].b);
                ans+=e[i].w;
                sm++;
                if(sm==ne)break;
            }
        }
        return ans;
    }
}al;
int n,m,k,c;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>yu[i].a>>yu[i].b>>yu[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>yu[j+m+(i-1)*n].w;
            yu[j+m+(i-1)*n].a=j;
            yu[j+m+(i-1)*n].b=n+i;
        }
    }
    sort(yu+1,yu+m+k*n+1,cmp);
    al.init();
    al.n=n+k;
    al.m=m+k*n;
    al.ne=n+k-1;
    for(int i=1;i<=m+k*n;i++){
        al.e[i]=yu[i];
    }
    cout<<al.sum()<<endl;
    return 0;
}