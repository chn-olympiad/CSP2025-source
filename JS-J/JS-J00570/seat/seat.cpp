#include<bits/stdc++.h>
using namespace std;
int a[99900];
int b[20][20];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int m,n;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
      cin>>a[i];
}
int xm=a[1];
sort(a+1,a+1+n*m);
int cnt=m*n;
for(int i=1;i<=m;i++){
    if(i%2==0){
        for(int j=n;j>=1;j--){
            b[j][i]=a[cnt];
            cnt--;
        }
    }else{
        for(int j=1;j<=n;j++){
             b[j][i]=a[cnt];
            cnt--;
        }
    }
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(b[i][j]==xm){
            cout<<j<<" "<<i;
            return 0;
        }
    }
}
return 0;
}
