#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,y;
bool cmp(int xx,int yy)
{
	return xx>yy;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i>=2&&a[i]>a[1])
		{
			cnt++;
		}
	}
	if(cnt%n==0)
	{
		x=cnt/n;
		if(x%2==1)
		{
			y=n;
		}
		else
		{
			y=1;
		}
		cout<<x<<' '<<y;
		return 0;
	}
	else
	{
		x=cnt/n+1;
	}
	if(x%2==1)
	{
		y=cnt%n;
	}
	else
	{
		y=n+1-cnt%n;
	}
	cout<<x<<' '<<y;
	return 0;
}