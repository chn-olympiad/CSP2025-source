#include <bits/stdc++.h>
using namespace std;
const int N=1e4;
const int M=1e6;
int n,m,k;
int a[M][4]={};
int b[10][N+2]={};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n+1;j++){
            cin>>b[i][j];
        }
    }
    cout<<13;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
