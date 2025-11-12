#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum,k,h[15][15],p=0,q[15][15],g=1;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=m*n;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    sum=a[1];
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            p++;
            h[i][j]=a[p];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i%2!=0){
                q[i][j]=h[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        g=1;
        for(int j=m;j>=1;j--){
          if(i%2==0){
                q[i][j]=h[i][g];
                g++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(sum==q[i][j]){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
