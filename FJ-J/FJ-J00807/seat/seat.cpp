#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],a1,c,r;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	cin>>a1;
	for(int i=1;i<=m*n-1;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+m*n,cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(a1>a[i])
		{
			a1=i;
			break;
		}
	}
	c=(a1-1)/n+1;
	if(c%2==1)
	{
		r=a1-(c-1)*n;
	}
	else
	{
		r=n-(a1-(c-1)*n)+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
