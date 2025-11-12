#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct lu{
    int u,v;
    long long w;
}a[2000005],d[2000005];
int cnt;
long long c[15],b[15][10005],e[10005];
long long mx=0x3f3f3f3f3f3f3f3f;
int fa[10005];
int root(int x){
    if(x==fa[x]) return x;
    return fa[x]=root(fa[x]);
}
void unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y) return ;
    fa[x]=y;
}
void init(){
    for(int i=1;i<=n;i++) fa[i]=i;
}
bool cmp(lu x,lu y){
    return x.w<y.w;
}
bool same(int x,int y){
    return root(x)==root(y);
}
long long solve(){
    init();
    int x=n;
    long long ans=0;
    for(int i=1;i<=cnt;i++){
        d[i].u=a[i].u;
        d[i].v=a[i].v;
        d[i].w=a[i].w;
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        //cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
        if(!same(a[i].u,a[i].v)){
            unite(a[i].u,a[i].v);
            ans+=a[i].w;
            x--;
            if(x==1){
                break;
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        a[i].u=d[i].u;
        a[i].v=d[i].v;
        a[i].w=d[i].w;
    }
    for(int i=1;i<=k;i++){
        if(e[i]>0) ans+=c[i];
    }
    return ans;
}

void dfs(int x){
    if(x==k+1){
        mx=min(mx,solve());
        return ;
    }
    int y=cnt;
    for(int i=1;i<=n;i++){
        a[++cnt].u=x;
        a[cnt].v=i;
        a[cnt].w=b[x][i];
    }
    e[x]++;
    dfs(x+1);
    cnt=y;
    e[x]--;
    dfs(x+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,x,y,z;i<=m;i++){
        cin>>x>>y>>z;
        a[i].u=x;
        a[i].v=y;
        a[i].w=z;
    }
    cnt=m;
    bool f=0;
    for(int i=1,x;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0) f=1;
        for(int j=1,y;j<=n;j++){
            cin>>b[i][j];
        }
    }
    if(f==1) dfs(1);
    else{
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                a[++cnt].u=i;
                a[cnt].v=j;
                a[cnt].w=b[i][j];
            }
        }
        sort(a+1,a+cnt+1,cmp);
        for(int i=1;i<=cnt;i++){
            if(!same(a[i].u,a[i].v)){
                unite(a[i].u,a[i].v);
                n--;
                mx+=a[i].w;
                if(n==1) break;
            }
        }
    }
    cout<<mx;
    return 0;
}
