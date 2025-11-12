#include<bits/stdc++.h>
using namespace std;
const int N=10024,M=1000046;
#define int unsigned long long
int n,m,k,c[N],a[N][N];
struct Edge{
    int u,v,w;
    bool operator<(const Edge& e)const{
        return w<e.w;
    }
};
vector<Edge> edge;
int f[N];
int getf(int p){
    if(f[p]==p) return p;
    return f[p]=getf(f[p]);
}
void combine(int x,int y){
    f[getf(x)]=getf(y);
}
int kruskal(int p){
    int ans=0;
    vector<Edge> tedge;
    tedge=edge;
    for(int i=0;i<k;i++){
        if((p>>i)&1){
            ans+=c[i];
            for(int j=0;j<n;j++) tedge.push_back({n+i,j,a[i][j]});
        }
    }
    sort(tedge.begin(),tedge.end());
    for(int i=0;i<n;i++) f[i]=i;
    for(int i=0;i<m;i++){
        if(getf(edge[i].u)!=getf(edge[i].v)){
            combine(edge[i].u,edge[i].v);
            ans+=edge[i].w;
        }
    }
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
            int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int ans=kruskal(0);
    for(int p=1;p<(1ULL<<(k+1));p++){
        int tmp=kruskal(p);
        if(tmp<ans)ans=tmp;
    }
    cout<<ans<<endl;
    return 0;
}
