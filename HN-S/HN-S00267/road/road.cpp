#include<bits/stdc++.h>
#define int long long
#define N 5000005
using namespace std;
int n,m,k,tot;
int fa[N],siz[N];
vector<pair<int,int>> g[N];
struct node{
    int x,y,z;
    bool operator<(const node&t)const{
        return z<t.z;
    }
}a[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx^fy){
        fa[fy]=fx,siz[fx]+=siz[fy];
        // cout<<x<<" "<<y<<" "<<siz[fy]<<endl;
    }
}
void solve1(){
    for(int i=1;i<=n+15;i++) fa[i]=i;
    for(int i=1;i<=n;i++) siz[i]=1;
    int res=0;
    for(int i=1;i<=tot;i++){
        if(find(a[i].x)==find(a[i].y)) continue;
        unionn(a[i].x,a[i].y);
        res+=a[i].z;
        if(siz[find(a[i].x)]==n){
            cout<<res<<"\n";
            exit(0);
        }
    }
    cout<<res<<'\n';
    exit(0);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>a[i].x>>a[i].y>>a[i].z;
        // g[a[i].x].push_back({a[i].y,a[i].z});
        // g[a[i].y].push_back({a[i].x,a[i].z});
    }
    tot=m;
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        for(int j=1;j<=n;j++){
            int y;
            cin>>y;
            a[++tot]={n+i,j,x+y};
        }
    }
    // cout<<tot<<endl;
    sort(a+1,a+tot+1);
    // if(!k) solve1();
    solve1();
}