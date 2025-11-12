#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int n,m,k,c[11],a[11][1000005],fa[N],cnt,res;
int find(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find(fa[x]);
}
void merge(int a,int b){
    fa[a]=find(b);
}
struct node{
    int u,v,w;
}x[N];
bool cmp(node a,node b){
    return a.w<=b.w;
}
void solve(){
    cnt=0;
    res=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>x[i].u>>x[i].v>>x[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    sort(x+1,x+1+m,cmp);
    for(int i=1;i<=m;i++){
        int a=find(x[i].u);
        int b=find(x[i].v);
        if(a!=b){
            //cout<<x[i].u<<" "<<x[i].v<<"\n";
            cnt++;
            merge(x[i].u,x[i].v);
            res+=x[i].w;
        }
    }
    cout<<res;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}