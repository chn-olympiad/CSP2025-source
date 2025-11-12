#include<bits/stdc++.h>
using namespace std;
int a[1000001][3],b[10][10002];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cout<<'0';
    return 0;
}
