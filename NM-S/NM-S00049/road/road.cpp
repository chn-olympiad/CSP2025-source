#include<bits/stdc++.h>
using namespace std;
int n=0, m=0, k=0;
int w[100005], u[100005], v[100005], c[15], a[15][100005];

int cost(int )

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    cin>>n>>m>>k;
    for(int i=0; i<=m-1; i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=0; i<=k-1; i++){
        cin>>c[i];
        for(int j=0; j<=n-1; j++){
            cin>>a[i][j];
        }
    }

    return 0;
}