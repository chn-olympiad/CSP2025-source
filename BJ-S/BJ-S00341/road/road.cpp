#include<iostream>
using namespace std;
int n,m,k;
int u[1000001],v[1000001],w[1000001];
int c[11],ca[11][100001];
int tota=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        tota=tota+w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>ca[i][j];
        }
    }
    cout<<tota;
    return 0;
}
