#include<bits/stdc++.h>
using namespace std;

int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
int m,n;
cin>>m>>n;
int a[m*n+1];
for(int i=1;i<=m*n;i++){
    cin>>a[i];
}
int xm=a[1];
sort(a+1,a+m*n+1);
int c[m+1][n+1];
int sum=m*n;
/*for(int i=1;i<=m*n;i++){
    cout<<a[i]<<endl;
}*/
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        c[j][i]=a[sum];
        if(a[sum]==xm){
           if(i%2==1){
               cout<<i<<' '<<j;
               return 0;
            }else{
            cout<<i<<' '<<n+1-j;
            return 0;
            }

           // cout<<i<<' '<<j;
        }
        sum--;
    }
}
}
