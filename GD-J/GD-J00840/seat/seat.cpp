#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,y;
	cin>>x;
	a[1] = x;
	for(int i = 2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i] == x)
		{
			y = i;
			break;
		}
	}
	cout<<((y-1)/n)+1<<' ';
	if((((y-1)/n)+1)&1)
	{
		cout<<(y-1)%n+1;
	}
	else
	{
		cout<<n-y%n+1;
	}
	return 0;
}
