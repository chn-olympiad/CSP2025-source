#include <bits/stdc++.h>
using namespace std;
int seat[15][15];
int n,m;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
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
	int mark=a[1],num;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==mark)
		{
			num=i;
			break;
		}
	}
	int x,y;
	x=(num-1)/n+1;
	int l=num%n;
	if(x%2==0)
	{
		y=n-l+1;
		if(l==0)
		{
			y=1;
		}
	}
	else
	{
		y=l;
		if(y==0)
		{
			y=n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
