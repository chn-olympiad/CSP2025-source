#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int num;
int x,y;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			num=a[i];
		}
	}
	int seat;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)
		{
			seat=i;
		}
	}
	x=seat/n;
	y=seat%n;
	if(y!=0)
	{
		x++;
	}
	if(x%2==0)
	{
		y=n-y+1;
	}
	if(y==0)
	{
		y=n;
	}
	cout<<x<<' '<<y<<endl;
	return 0;
}
