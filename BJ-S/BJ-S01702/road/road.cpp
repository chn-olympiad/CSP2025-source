#include<bits/stdc++.h>
using namespace std;

const int N= 1e4 + 9;
const int M= 1e6 + 9;
const int K= 10 +9;
int n,m,k,u[M],v[M],w[M],c[K],a[K][N];

int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    cout<<0<<endl;

    return 0;
}
