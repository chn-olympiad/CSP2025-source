#include<bits/stdc++.h>
using namespace std;
const int maxn=10002;
const int maxk=12;
int n,m,k;
int c[maxk];
int a[maxn][maxk];
int d[maxn][maxn];
int answer=0;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    memset(d,-1,sizeof(d));
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        d[u][v]=d[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[j][i];
        }
        for(int j=1;j<=n;j++){
            for(int kk=1;kk<=n;kk++){
                if(j==kk||d[j][kk]==-1)continue;
                d[j][kk]=min(d[j][kk],a[j][i]+a[kk][i]);
                d[kk][j]=d[j][kk];
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]!=-1&&i<j){
                answer+=d[i][j];
            }
        }
    }
    
    cout<<answer;
    return 0;
}

