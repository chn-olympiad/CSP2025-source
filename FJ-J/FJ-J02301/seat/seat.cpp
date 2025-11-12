#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m,c,r;
int main(){
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
 cin>>n>>m;
 for(int i=1;i<=n*m;i++) cin>>a[i];
 int t=a[1];
 sort(a+1,a+n*m+1);
 int x=m*n/2,h=1,w=n*m;
 if(a[n*m]==t) x=n*m;
 else{
 	while(1){
  if(a[x]==t) break;
  else if(a[x]<t){
   h=x;
   x=(h+w)/2;
  }
  else{
   w=x;
   x=(h+w)/2;
  }
 }
 }
 x=n*m-x+1;
 if(x%n==0) c=x/n;
 else c=x/n+1;
 if(c%2==0) r=n-(x-(n*(c-1)))+1;
 else r=x-(n*(c-1));
 cout<<c<<" "<<r;
 return 0;
}