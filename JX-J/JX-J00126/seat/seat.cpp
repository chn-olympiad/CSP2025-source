#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,ans,x=1,y=1,d=1;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++){
	   cin>>a[i];
   }
   ans=a[1];
   sort(a+1,a+n*m+1);
   int c=1;
   for(int i=1;i<=m;i++){
       for(int j=1;j<=n;j++){
	   if(a[n*m-d+1]==ans){
		   cout<<x<<" "<<y;
		   return 0;
	   }
	   d++;
	   y+=c;
    }
    c*=-1;
    x++;
    if(y>n) y=n;
    if(y<1) y=1;
   }
   return 0;
}
