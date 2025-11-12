#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[115];
	int m,n;
	cin>>n>>m;
	cin>>a[1];
	int k=a[1];
	for(int i=2;i<=m*n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	int ft;
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==k)
		{
			ft=i;
			break;
		}
	}
	int f=m*n-ft+1;
	int seata,seatb;
	if(f%n==0)
	{
		seata=f/n;
		if(seata%2==0)
		{
			seatb=1;
		}
		else seatb=n;
	}
	else 
	{
		seata=f/n+1;
		if(seata%2==0)
		{
			seatb=n-f%n+1;
		}
		else seatb=f%n;
	}
	printf("%d %d",seata,seatb);
	return 0;
} 
