#include<bits/stdc++.h>
using namespace std;
int n,m,s[15][15],a[105],R,cnt;
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
		cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
			cnt=i;
	}
	int x=cnt/n+1,y=cnt%n;
	if(x%2==1)
	{
		if(y==0)
		{
			x--;
			y=1;
		}
	}
	else
	{
		if(y==0)
		{
			x--;
			y=n;
		}
		else
			y=n-y+1;
	}
	
	cout<<x<<" "<<y;
	return 0;
}
