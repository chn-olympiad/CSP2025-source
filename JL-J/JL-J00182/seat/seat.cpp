#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int r;
int zn,zm;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
            cin>>a[n][m];
    }
    }
    r=a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int z=1;z<=n;z++){
                for(int x=1;x<=m;x++){
                    if(a[i][j]>a[z][x]&&(i<z&&j<x)){
                        swap(a[i][j],a[z][x]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        a[zn][zm]=a[i][j];
    }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        if(r==a[i][j]){
            cout<<m<<" "<<n;
        }else{
        cout<<m-1<<" "<<n-2;
        }
    }
    }

    return 0;
}
