#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
   int n,m,c=1;
   cin>>n>>m;
   cin>>a[1];
   for(int i=2;i<=n*m;++i){
    cin>>a[i];
    if(a[i]>a[1]) c++;
   }
   int y=c/n;
   if(y*n<c){
    int t=c-n*y;
    cout<<y+1<<' ';
    if(y%2==0) cout<<t;
    else cout<<n-t;
   }
   else{
    cout<<y<<' ';
    if(y%2==0) cout<<1;
    else cout<<n;
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}
