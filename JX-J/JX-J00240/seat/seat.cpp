#include<bits/stdc++.h>
using namespace std;
int n,m,r,l;
int a[110],b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n;i>=1;i--){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                b[i][j]=a[i*m+m-j+1];
            }
        }else{
            for(int j=1;j<=m;j++){
                b[i][j]=a[i*m+j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==r){
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
