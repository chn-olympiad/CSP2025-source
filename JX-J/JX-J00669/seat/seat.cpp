#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   int n,m;
   cin>>n>>m;
   int a[15][15]={0},b,c[101]={0},d=1,e=1,f=0;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cin>>a[i][j];
        c[a[i][j]]++;
    }
   }
   b=a[1][1];
   for(int i=100;i>=0;i--){
        if(i==b){
            break;
        }
        if(c[i]>0){
            d++;
        }
   }
   for(int i=1;i<=d;i++){
    if(e%2==1){
        if(f<m){
            f++;
        }
        else{
            e++;
        }
    }
    else{
        if(f>1){
            f--;
        }
        else{
            e++;
        }
    }
   }
   cout<<e<<' '<<f;
   return 0;
}
