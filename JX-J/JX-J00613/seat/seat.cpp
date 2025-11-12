#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],z=1,x,y;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.ans","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++){
	   cin>>a[i];
	   if(a[1]<a[i])z++;
   }
   if(z%n==0)x=z/n;
   else x=z/n+1;
   cout<<x<<" ";
   y=z%n;
   if(x%2==0&&y!=0)cout<<n-y+1;
   else if(x%2==0&&y==0)cout<<"1";
   else if(x%2==1&&y!=0)cout<<y;
   else if(x%2==1&&y==0)cout<<n;
   return 0;
}
