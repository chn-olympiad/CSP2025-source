#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,x,tx,ty;
int main()
{
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++) cin>>a[i];
   x=a[1];
   sort(a+1,a+n*m+1,greater<int>());
   tx=ty=1;
   for(int i=1;i<=n*m;i++)
   {
	   if(tx>n) 
	   {
		   ty++;
		   tx=n;
	   }
	   if(tx<1) 
	   {
		   ty++;
		   tx=1;
	   }
	   if(a[i]==x) 
	   {
		   cout<<ty<<' '<<tx;
		   return 0;
	   }
	   if(ty%2==1) tx++;
	   else tx--;
   }
   return 0;
}
