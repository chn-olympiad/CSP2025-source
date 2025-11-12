#include<bits/stdc++.h>
using namespace std;
long long n,m,k,p[100001],gz[11],dt[11][10001],u[100001],v[100001],bj=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>p[i]>>u[i]>>v[i];
    }
    for(int i=1;i<=k;i++){
        cin>>gz[i];
        for(int j=1;j<=n;j++){
            cin>>dt[i][j];
            if(gz[i]==0 and dt[i][j]==0){
                bj=1;
            }
        }
    }
    if(bj==1){
        cout<<0;
        return 0;
    }
    return 0;
}
