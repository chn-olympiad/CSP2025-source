#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005],n,m,t,lie;
long long ans;
int jie(int x)
{
	int y;
	for (int i=x;i>=2;i--)
	{
		y+=i;
	}
	return y;
}
int erfen(int l,int r,int x)
{
	int mid;
	while (l<r)
	{
		mid=(r-l)/2+l;
		if (b[mid]<=x)
		{
			l=mid+1;
		}
		else r=mid;
	}
	return r;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for (int i=1;i<=n;i++)
	{
		cout<<b[i];
	}
	for (int i=n;i>=3;i--)
	{
		if ((i-erfen(1,i-1,a[i]))<2)
		continue;
		ans+=jie((i-erfen(1,i-1,a[i])));
	}
	cout<<ans;
	return 0;
 } 
