#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c=0,r=0;
	cin>>m>>n;
	long long a[m*n+5]={};
	int cnt,x;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
		x=a[1];
	}
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]<=a[i+1])
		{
			a[i]=a[i+1];
		}

	}
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]=x)
		{
			cnt=i;	
		}	
	}
	c=cnt/n;
	if(cnt%n==1) 
	{
		r=c*n-cnt;
	}
	else
	{
		r=c*n-cnt+1;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
