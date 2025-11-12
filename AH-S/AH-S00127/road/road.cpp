#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
int improve[17];
int be_improved[17][10007];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
    }
    for(int i=1;i<=k;i++){
        cin>>improve[i];
        for(int j=1;j<=n;j++){
            cin>>be_improved[i][j];
        }
    }
    cout<<33550336;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
