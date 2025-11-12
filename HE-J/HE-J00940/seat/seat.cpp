#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int q,int w)
{
	return q>w;
}
int erfen(int o,int p)
{
	int ans=1,l=1,ri=o;
	while (l<=ri)
	{
		int mid=(l+ri)/2;
		if(a[mid]>=p)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			ri=mid-1;
		}
	}
	return ans;
}
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,r,x=0,y=0;
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for (int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int wei=erfen(m*n,r);
	if (wei%n==0)
	{
		x=wei/n;
	}
	else
	{
		x=wei/n+1;
	}
	if (x%2==1)
	{
		y=wei%n;
		if (y==0)
		{
			y=n;
		}
	}
	else
	{
		y=wei%m;
		if (y==0)
		{
			y=n;
		}
		y=n-y+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
