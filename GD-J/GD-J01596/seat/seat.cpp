#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],f[105][105],x=1,y,w;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	w=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(x%2)y++;
		else y--;
		if(y==0)
		{
			x++;
			y=1;
		}
		if(y==n+1)
		{
			x++;
			y=n;
		}
		if(a[i]==w)cout<<x<<" "<<y<<endl;
	}
}

