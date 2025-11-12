#include<bits/stdc++.h>
using namespace std;
int n,m,a1,a[105],l,b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a1;
    l=m*n;
    for(int i=1;i<=n*m-1;i++){
        cin>>a[i];
    }
    a[n*m]=a1;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=m;j>=1;j--){
                b[i][j]=a[l];
                l--;
            }
        }
        else{
            for(int j=1;j<=m;j++){
                b[i][j]=a[l];
                l--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==a1){
                cout<<i<<' '<<j;
            }
        }
    }
    return 0;
}
