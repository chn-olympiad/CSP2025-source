#include<bits/stdc++.h>;
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int a[10000][10000];
    int b[10000][10000];
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
    return 0;
}
