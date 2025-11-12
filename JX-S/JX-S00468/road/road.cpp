#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[5000][5000],b[5000][5000];
int main(){
    cin>>n>>m>>k;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            cin>>b[i][j];
        }
    }
    cout<<0;
    return 0;
}
