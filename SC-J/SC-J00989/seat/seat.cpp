#include<bits/stdc++.h>
using namespace std;
short n,m,a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	short t=a[1];
	sort(a+1,a+1+n*m);
	bool f=0;
	for(int i=n*m,x=1,y=0;i>=1;i--)
	{
		if(!f)
		{
			y++;
			if(y>n)
			{
				y--;
				x++;
				f=1;
			}
		}
		else
		{
			y--;
			if(y<1)
			{
				y++;
				x++;
				f=0;
			}
		}
		if(a[i]!=t)continue;
		cout<<x<<' '<<y;
		return 0;
	}
	return 0;
}