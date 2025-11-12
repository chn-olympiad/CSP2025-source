#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,a[100],a1,mn,gj,c,r;
	cin>>n>>m;
	mn=m*n;
	memset(a,0,sizeof(a));
	for(int i=0;i<mn;i++)
	{
		cin>>gj;
		a[i]=gj;
	}
	a1=a[0];
	for(int i=1;i<=mn;i++)
	{
		for(int j=0;j<mn-i;j++)
		{
			if(a[j]<a[j+1])
			{
				gj=a[j];
				a[j]=a[j+1];
				a[j+1]=gj;
			}
		}
	}
	for(int i=0;i<mn;i++)
	{
		if(a[i]==a1)
		{
			a1=i+1;
			break;
		}
	}
	if(a1/n%2==0)if(a1%n==0)r=1;else r=a1%n;else if(a1%n==0)r=n;else r=n-a1%n+1;
	if(a1%n==0)c=a1/n;else c=a1/n+1;
	cout<<c<<" "<<r;
	return 0;
}
