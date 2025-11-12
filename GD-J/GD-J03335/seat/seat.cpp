#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[120],pd;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	pd=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(pd==a[i])
		{
			pd=i;
			break;
		}
	}
	int x=0,y=1;
	while(pd--)
	{
		if(y%2) x++;
		else x--;
		if(x>n&&y%2)
		{
			y++;
			x=n;
		}
		else if(x<=0&&!(y%2))
		{
			y++;
			x=1;
		}
	}
	cout<<y<<" "<<x;
}
/*
3 3 

94 95 96 97 98 99 100 93 92

*/
