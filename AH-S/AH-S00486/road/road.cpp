#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,k,u[N],v[N],w[N],c[N],a[N];
long long cnt;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        cnt+=w[i];
    }
    for(int i=1;i<=k;i++){
            cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
    }
    cout<<cnt;
    return 0;
}
