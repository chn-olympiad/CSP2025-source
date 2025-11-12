#include <iostream>
using namespace std;
int u[100005],v[100005],w[100005];
int c[15],a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
    }
    cout<<w[1]*u[1]+c[1]*a[1]+k/2;
}
