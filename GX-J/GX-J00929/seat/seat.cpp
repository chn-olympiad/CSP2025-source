#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m,c,r,x;
  int a[101];
  cin>>n>>m;
  for(int i=1;i<=n*m;i++)
  {
	int k;
    cin>>k;
    a[i]=k;
  }
  x=a[1];
  for(int i=1;i<=n*m;i++)
    for(int j=i+1;j<=n*m;j++)
    {
      if(a[i]<a[j]) swap(a[i],a[j]);
	}
  for(int i=1;i<=n*m;i++)
  {
   if(a[i]==x)  
   {
	if(i%n==0) {r=n;c=i/n;}
	else {r=i%n;c=i/n+1;} 
   }	  
  }
  if(c%2==0)
  {
   if(r==1) r=n;
   else if(r==n) r=1;
   else r=n-(r-1);		
  }
  cout<<c<<" "<<r;
  return 0;
}
