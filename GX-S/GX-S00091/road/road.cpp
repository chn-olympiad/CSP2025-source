#include<bits/stdc++.h>
using namespace std;
long long u,v,w,k,n,m,c[100005],a[1006][100005];
int main(){
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m+1;i++){
        cin>>u[i],v[i],w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=k;j++){
            cin>>a[i][j];
        }
    }
    cout<<
    return 0;
}
//k==0,n==10^4,m==10^6;
