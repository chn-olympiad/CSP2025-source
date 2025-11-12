#include <bits/stdc++.h>
using namespace std;

int n,m,x[110];
int a[15][15];

int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   int f=0,t;
   cin>>n>>m;
   for(int i=1;i<=n*m;i++){
       cin>>x[i];
   }
   t=x[1];
   sort(x+1,x+1+n*m,greater<int>());
   for(int j=1;j<=m;j++){
       if(j%2==1){
           for(int i=1;i<=n;i++){
               f++;
               a[i][j]=x[f];
           }
       }else{
           for(int i=n;i>=1;i--){
               f++;
               a[i][j]=x[f];
           }
       }
   }
   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
           if(a[i][j]==t){
               cout<<j<<" "<<i;
           }
       }
   }
   return 0;
}
