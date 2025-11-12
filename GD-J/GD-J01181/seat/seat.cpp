#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10005];
	int mx=0,pos=0,x,y;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		mx=a[1];
		if(i>1&&a[i]>a[1])
		{
			pos++;
		} 	
	}
	pos++;
	for(int i=1;i<=m;i++)
	{
		if(pos<=i*n&&pos>(i-1)*n) x=i;
		if(x%2==0)  y=n-pos%n+1;
		if(x%2!=0)
		{
			if(pos%n!=0) y=pos%n;
			if(pos%n==0) y=n;
		}
	} 
	cout<<x<<" "<<y;
 } 
