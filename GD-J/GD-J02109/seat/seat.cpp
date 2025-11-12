#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,x=1,y=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(y>n||y<1)
		{
			x++;
			if(x%2==1) y=1;
			else y=n;
		}
		if(a[i]==t)
		{
			cout<<x<<" "<<y;
			return 0;;
		}
		if(x%2==1) y++;
		else y--;
	}
	return 0;
}
