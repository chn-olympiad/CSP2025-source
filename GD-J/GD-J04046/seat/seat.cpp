#include <bits/stdc++.h>
using namespace std;
int a[105],cnt,n,m,c,r,num;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]>=num)
		{
			l=mid+1;
			cnt=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	c=cnt/n+1;
	if(c%2==1)
	{
		if(cnt%n==0)
		{
			r=n;
		}
		else
		{
			r=cnt%n;
		}
	}
	else
	{
		if(cnt%n==0)
		{
			r=1;
		}
		else
		{
			r=n-cnt%n+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
