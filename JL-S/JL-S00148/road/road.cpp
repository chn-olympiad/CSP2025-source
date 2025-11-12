#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,k,u,v,w,c[100000][100000],a[15][100000];
struct town{
    long long c;
    bool b;
};
town f[15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        c[u][v]=w;
        c[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        cin>>f[i].c;
        f[i].b=0;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        long long mi=1000000000;
        int h;
        for(int j=1;j<=n+k;j++){
            if(j<=n){
                if(c[i][j]){
                    mi=min(mi,c[i][j]);
                }
            }
            else if(f[j-n].b==0){
                if(mi>a[j-n][i]){
                    mi=a[j-n][i];
                    h=j-n;
                }
            }
            else{
                if(mi>a[j-n][i]){
                    mi=a[j-n][i];
                    h=0;
                }
            }
        }
        if(h){
            f[h].b=1;
        }
        ans+=mi;
    }
    cout<<ans;
    return 0;
}
