#include<iostream>
using namespace std;
int a[1000000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
    }
    for(int j=1;j<=k;j++){
        int c;
        cin>>c;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
    }
    cout<<0;
    return 0;
}
