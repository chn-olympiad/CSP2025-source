#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int uvw[10000000][3];
    for(int i = 1;i<=m;i++){
        cin>>uvw[i][1]>>uvw[i][2]>>uvw[i][3];
    }
    int ca[11][10001];
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            cin>>ca[i][j];
        }
    }
    return 0;
}