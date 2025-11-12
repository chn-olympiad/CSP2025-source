#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    int a[m][3];
    int b[k][n];
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
         cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }

    return 0;

}
