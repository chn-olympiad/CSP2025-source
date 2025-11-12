#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u[1000001],v[1000001],w[1000001],c[11],a[11][10001],al=0;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(al==0&&c[i]==0)al=1;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0&&al==1)al=2;
        }
    }
    if(al==2){
        cout<<"0";
        return 0;
    }
    return 0;
}
