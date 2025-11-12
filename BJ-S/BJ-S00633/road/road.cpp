#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
const int maxm = 1e6 + 10;
const int maxz = 20;
int n,m,k,cnt;
ll ans,c[maxz],a[maxn];
struct Edge{
    int u;
    int v;
    ll w;
}edge[maxm*2+1];
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=m/2;i++){
        ans=ans+edge[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        if(i!=1){
            continue;
        }
        sort(a+1,a+1+n);
        for(int j=1;j<=m/2;j++){
            ans=ans+a[j];
        }
    }
    cout<<ans+c[1];
    return 0;
}
