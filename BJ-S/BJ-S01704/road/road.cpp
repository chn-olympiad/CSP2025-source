#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int a[N][N];
int n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)    a[i][j]=1e9+7;
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        vector<int> t;
        int x;cin>>x;
        for(int j=1;j<=n;j++){
            int f;cin>>f;
            t.push_back(f);
        }
        for(int j=0;j<t.size();j++){
            for(int l=j+1;l<t.size();l++){
                a[j+1][l+1]=min(t[j]+t[l]+x,a[j+1][l+1]);
                a[l+1][j+1]=min(t[j]+t[l]+x,a[l+1][j+1]);
            }
        }
    }
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][l]+a[l][j]<a[i][j]){
                    a[i][j]=a[i][l]+a[l][j];
                }
            }
        }
    }
    long long ans=0;
    for(int l=1;l<n;l++){
        int minn=1e9+7,posx,posy;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(minn>a[i][j]){
                    minn=a[i][j];
                    posx=i,posy=j;
                }
            }
        }
        a[posx][posy]=1e9+7;
        ans+=minn;
    }
    cout<<ans;
    return 0;
}
