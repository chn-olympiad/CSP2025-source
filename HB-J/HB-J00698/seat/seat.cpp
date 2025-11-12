#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],x,y;
bool cmp(int a,int b)
{
   return a>b;
}
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  int k=n*m;
  for(int i=1;i<=k;i++)
	   cin>>a[i];
  int f=a[1];
  sort(a+1,a+1+k,cmp);
  for(int i=1;i<=k;i++)
   {
	   if(f==a[i])
	   {
		   int u=i%n,l=i/n;
		   if(u==0)
		   {
			  if(l%2==0)
			  {
				  x=1;
				  y=i/n;
			   }
			   else
			   {
				x=n;//hang
			    y=i/n;//lie
			   }
		   }
	       else
	       {
			  if(l%2==0)
			  {
				 x=u;
				 y=i/n+1;
			   }
			   else
			   {
				 x=n-u+1;//hang
			    y=i/n+1;//lie
			   }
		   }
	   }
   }
   cout<<y<<" "<<x<<endl;
 return 0;
}

