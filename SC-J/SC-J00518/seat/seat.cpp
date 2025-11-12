#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105]={};
int R;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			R=a[i];
		}
	}
	sort(a,a+n*m+1);
	int k=0;
	for(int i=n*m;i>0;i--)
	{
		k++;
		if(a[i]==R)
		{
			break;
		}
	}
	int c,r;
	
	c=k/n;
	if(k%n!=0)
	{
		c++;
	}
	if(c%2==1)
	{
		r=k%n;
		if(k%n==0)
		{
			r=n;
		}	
	}else
	{
		r=n-k%n+1;	
	}
	
	cout<<c<<" "<<r; 
	return 0;
 } 