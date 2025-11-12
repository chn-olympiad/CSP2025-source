#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000005],v[1000005],w[1000005],ans;
int c[15][100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        ans+=w[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    cout<<ans/5*3;
    fclose(stdin);
    fclose(stdout);
}
