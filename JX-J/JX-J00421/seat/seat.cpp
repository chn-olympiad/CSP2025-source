#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int main (){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int c,r;
    int cj,maxn=0,minn=100;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }for(int i=1;i<=n*m;i++){
        cin>>cj;
        if(cj>maxn){
            maxn=a[1][1];
        }if(cj<minn){
            minn=a[n][m];
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c=i;
            r=j;
        }
    }
    cout<<c<<r;
    return 0;
}
