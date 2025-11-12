#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int c=a[1],x=1,y=1;
	bool f=true;
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(c==a[i])
		{
			cout<<y<<" "<<x;
		}
		if(f) x++;
		else x--;
		if(x>n)
		{
			x=n;
			y++;
			f=false;
		}
		else if(x<1)
		{
			x=1;
			y++;
			f=true;
		}
	}
	return 0;
}
