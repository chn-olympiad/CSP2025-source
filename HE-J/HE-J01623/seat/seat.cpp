#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[15],b[15],sum,k;
int x,y,z=1;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
	}
	if(n==1&&m==1) 
	{
		cout<<a[1];
		return 0;
	}
	k=a[1];
	sort(a+1,a+sum+1);
	for(int i=sum,j=1;i>=1,j<=sum;i--,j++)
	{
		b[j]=a[i];
	}
	for(int i=1;i<=sum;i++)
	{
		if(b[i]==k)
		{
			z=i;
			break;
		}
	}
	if(z%n==0) x=z/n;
	else x=z/n+1;
	if(x%2==1)
	{
		if(x==1)  y=z;
		else y=z%n;
	}
	else y=n-(z%n)+1;
	cout<<x<<" "<<y;
	return 0;
}
