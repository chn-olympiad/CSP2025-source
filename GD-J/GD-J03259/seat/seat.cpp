#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
	int n,m;
	int d;
	int x=1,y=1;
	cin>>n>>m;
	int s=n*m;
	int a[s];
	cin>>a[1];
	int r=a[1];
	for(int i=2;i<=s;i++)
	{
		cin>>a[i];
	 } 
	 	for(int i=2;i<=s;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]<a[i])
			{
				d=a[j];
				a[j]=a[i];
				a[i]=d;
			}
		}
 }
 for(int i=1;i<=s;i++)
 {
  if(a[i]==r)
  {
  	cout<<x<<" "<<y;
  	break;
  }
  
	 if(x%2!=0) 
  {
  	y++;
  	if(y>m)
  	{
  		x++;
  		y--;
	  }
  }
  else 
  {
  	y--;
  	if(y<1)
  	{
  		x++;
  		y++;
	  }
  }
 }
 return 0;
}
