#include<bits/stdc++.h>
using namespace std;
    int main(){
       freopen("seat.in","r",stdin);
       freopen("seat.out","w",stdout);
       //
       int n,m,i,j,x,r,t;
       cin>>n>>m;
       int a[n+1][m+1];
       for(i=1;i<=n+1;i++){
        for(j=1;j<=m+1;j++){
            cin>>a[i][j];
            if(i==1&&j==1){
                r=a[i][j];
            }
        }
       }
       for(x=1;x<=n*m;x++){
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(j==1){
                    if(a[i][j]>a[i-1][m]){
                        t=a[i][j];
                        a[i][j]=a[i-1][m];
                        a[i-1][m]=t;
                    }
                }
                else{
                    if(a[i][j]>a[i][j-1]){
                        t=a[i][j];
                        a[i][j]=a[i][j-1];
                        a[i][j-1]=t;
                    }
                }
            }
        }
       }
       for(i=1;i<=n+1;i++){
        for(j=1;j<=m+1;j++){
            if(a[i][j]==r){
                cout<<i<<" "<<j;
            }
        }
       }
       return 0;
    }
