#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
vector<int> G[N];
int dis[N][N],a[15][N],c[15];
//int F[N];
int z[N*N];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    int u,v,w;
    cin>>n>>m>>k;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        dis[u][v]=dis[v][u]=w;
    }
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j) cin>>a[i][j];
        for(int j=1;j<=n;++j){
            for(int kk=1;kk<j;++kk){
                //cout<<j<<' '<<kk<<endl;

                dis[j][kk]=min(dis[j][kk],a[i][j]+a[i][kk]+c[i]);
                //cout<<dis[j][kk]<<endl;
            }
        }
    }
    //cout<<"You have no egg"<<endl;
    int tot=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            z[++tot]=dis[i][j];
        }
    }
    /*
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<dis[i][j]<<' ';
        }cout<<endl;
    }
    */
    sort(z+1,z+tot+1);
    int ans=0;
    for(int i=1;i<n;++i) ans+=z[i];
    cout<<ans<<endl;
    return 0;
}
