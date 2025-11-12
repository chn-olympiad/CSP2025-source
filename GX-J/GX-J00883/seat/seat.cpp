#include <bits/stdc++.h>
using namespace std;
int m,n,a[200],b,c=1,x,y,z;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a,a+m*n+1);
    for(int i=m*n;i>=1;i--){
        z=z+1;
        if(a[i]==b){
            x=z;
        }
    }
    for(int i=1;i<=m;i++){
        if(c==1){
            for(int j=c;j<=n;j++){
                y=y+1;
                if(y==x){
                    cout<<i<<" "<<j;
                }
            }
            c=n;
        }
        else if(c==n){
            for(int k=n;k>=1;k--){
                y=y+1;
                if(y==x){
                    cout<<i<<" "<<k;
                }
            }
            c=1;
        }
    }
    return 0;
}
