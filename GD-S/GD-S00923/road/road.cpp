#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k;
struct node{
    int v,w;
};
vector<node> e[N];
int c[N],b[N][N];
bool allzero;
int dis[N][N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i])
            allzero=1;
        for(int j=1;j<=n;j++) {  
            cin>>b[i][j];
            if(b[i][j])
                allzero=1;
            }
    }
    if(!allzero)
        cout<<0<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}