#include<bits/stdc++.h>
using namespace std;
int a[101],flag[101],i,n,m,num,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=(n*m);i=i+1)
	{
		cin>>a[i];
	}
	for(i=1;i<=n*m;i=i+1)
	{
		flag[a[i]]=1;
	}
	for(i=100;i>=1;i=i-1)
	{
		if(flag[i]==1)
		{
			num=num+1;
		}
		if(i==a[1])
		{
			break;
		}
	}
	if((num%n)==0)
	{
		c=(num/n+1);
		cout<<(num/n);		
	}
	else
	{
		c=(num/n+1);
		cout<<(num/n+1);
	}
	cout<<" ";
	if(c%2==1)
	{
		cout<<(num%n);
	}
	else
	{
		cout<<(n-(num%n)+1);
	}
	return 0;
}

