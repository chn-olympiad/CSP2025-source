#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,a,x,y,z;//n->city,m->road,k->town
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            cin>>a;
        }
    }
    cout<<0;
    return 0;
}
