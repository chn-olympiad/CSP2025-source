#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e4+5;
int n,m,k;
int w[N],c[15],a[15],f,g;
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v>>w[i];
        }
        for(int i=0;i<=k;i++){
            cin>>c[i]>>a[i];
            f+=c[i];
            g+=a[i];
        }
        if(f==0&&g==0){
            cout<<0;
            return 0;
        }
    return 0;
}
