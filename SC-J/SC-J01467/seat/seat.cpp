#include<bits/stdc++.h>
using namespace std;
long long a[200];
long long n,m,i,j,cj,l,r,mid,wz,hang,lie,lie2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if (i==1)
		{
			cj=a[i];
		}
	}
	sort(a+1,a+n*m+1);
	l=1;
	r=n*m;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (a[mid]==cj)
		{
			wz=mid;
			break;
		}
		else if (a[mid]<cj)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	wz=n*m-wz+1;
	lie=wz/n;
	lie2=lie;
	if (wz%n>0)
	{
		lie2++;
	}
	if (lie%2==0)
	{
		if (wz%n==0)
		{
			hang=1;
		}
		else
		{
			hang=wz%n;
		}
	}
	else
	{
		if (wz%n==0)
		{
			hang=n;
		}
		else
		{
			hang=n-wz%n+1;
		}
	}
	cout<<lie2<<" "<<hang;
	return 0;
}