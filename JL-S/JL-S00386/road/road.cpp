#include<bits/stdc++.h>
using namespace std;

int n,m,p,u,v,w,sum;
int z;
int a[10001];
int dis[1001][1001];
int f[1001];
int floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
}


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>p;
    for(int i=1;i<=n+p;i++){
        for(int j=1;j<=n+p;j++){
            if(i!=j){
               dis[i][j]=1e9;
            }
            else{
                dis[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        dis[u][v]=dis[v][u]=min(dis[u][v],w);
    }
    for(int i=1;i<=p;i++){
        cin>>z;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            a[j]=a[j];
            dis[j][i+n]=dis[i+n][j]=a[j];
        }
    }
    n=n+p;
    floyd();
   for(int i=1;i<=n-p-1;i++){
      for(int j=i+1;j<=n-p;j++){
            sum+=dis[i][j];
        }
    }
    cout<<sum;
    return 0;
}
