#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+9;
long long n,m,k;
unsigned long long mp[N][N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        mp[u][v]=w;
        mp[v][u]=w;
    }
    for(long long k=1;k<=m;k++){
        for(long long i=1;i<=m;i++){
            for(long long j=1;j<=m;j++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][k]);
            }
        }
    }
    cout<<mp[1][n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
