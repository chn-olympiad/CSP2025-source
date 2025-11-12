#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxm=1e6+5;

int a[maxn][maxn],ans=0,c[15];
bool vis[maxn];
int dis[maxn];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    if(k==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=1e9;
            }
        }
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            a[u][v]=a[v][u]=w;
        }
        for(int i=1;i<=n;i++){
            dis[i]=a[1][i];
        }

        for(int i=1;i<n;i++){
            int p=-1;
            for(int j=1;j<=n;j++) if(!vis[j]){
                if(p==-1||dis[p]>dis[j]) p=j;
            }
            ans+=dis[p];vis[p]=1;
            for(int j=1;j<=n;j++){
                dis[j]=min(dis[j],a[p][j]);
            }
        }
        cout<<ans<<endl;
        return 0;
    } else {
        for(int i=1;i<=n;i++){
            int u,v,w;
            cin>>u>>v>>w;
            a[u][v]=a[v][u]=w;
        }
        for(int i=1;i<=k;i++){
            cin>>c[i];
            for(int j=1;j<=n;j++){
                int w;cin>>w;
                a[n+i][j]=a[j][n+i]=w;
            }
        }
        bool flag=0;
        for(int i=1;i<=k;i++) if(c[i]) flag=1;
        if(flag==0){
            for(int i=1;i<=n+k;i++){
                dis[i]=a[1][i];
            }

            for(int i=1;i<n+k;i++){
                int p=-1;
                for(int j=1;j<=n+k;j++) if(!vis[j]){
                    if(p==-1||dis[p]>dis[j]) p=j;
                }
                ans+=dis[p];vis[p]=1;
                for(int j=1;j<=n+k;j++){
                    dis[j]=min(dis[j],a[p][j]);
                }
            }
            cout<<ans<<endl;
        } else if(flag==1){
            for(int i=1;i<=n+k;i++){
                dis[i]=a[1][i];
            }

            for(int i=1;i<n+k;i++){
                int p=-1;
                for(int j=1;j<=n+k;j++) if(!vis[j]){
                    if(p==-1||dis[p]>dis[j]) p=j;
                }
                ans+=dis[p];vis[p]=1;
                for(int j=1;j<=n+k;j++){
                    dis[j]=min(dis[j],a[p][j]);
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }


}
