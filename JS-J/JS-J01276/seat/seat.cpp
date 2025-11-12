#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++)cin>>a[i];
   r=a[1];
   sort(a+1,a+n*m+1);
   for(int i=1;i<=n*m;i++){
      if(a[i]==r){
        int x=(n*m-i+1)%n,y=(n*m-i+1)/n;
        if(x!=0)y++;
        else x=n;
        if(y%2==1)cout<<y<<" "<<x;
        else cout<<y<<" "<<n-x+1;
      }
   }
   return 0;
}
