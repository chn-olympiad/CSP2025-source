#include <bits/stdc++.h>
#define N 10003
using namespace std;
int n,m,k,c[N],a[N][N],mp[N][N],ans;
bool flag=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(mp,0x3f,sizeof mp);
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        mp[u][v]=mp[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]) flag=1;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]) flag=1;
        }
    }
    if(!flag){
        cout<<"0\n";
        return 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
                int minn=mp[i][j],mini=0;
                for(int o=1;o<=k;o++){
                    if(c[o]+a[i][o]+a[o][j]<=minn) minn=c[o]+a[i][o]+a[o][j],mini=o;
                }
                mp[i][j]=minn,c[mini]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) ans+=mp[i][j];
    }
    cout<<ans<<'\n';
    return 0;
}
