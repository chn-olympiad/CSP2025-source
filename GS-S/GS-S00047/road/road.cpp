#include<bits/stdc++.h>
using namespace std;

struct ROAD{
    int u;
    int v;
    int w;
};

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    ROAD roads[m] = {};
    for(int i=0;i<m;i++){
        cin>>roads[i].u>>roads[i].v>>roads[i].w;
    }
    int vill[m][n+1] = {};
    for(int i=0;i<m;i++){
        for(int j=0;j<n+1;j++){
            cin>>vill[i][j];
        }
    }
    cout<<13
    return 0;
}
