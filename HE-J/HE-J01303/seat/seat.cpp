#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	int R=a[0];
	sort(a,a+n*m);
	int t=1;
	int x=1,y=1;
	for(int i=n*m-1;i>=0;i--)
	{
		if(a[i]==R) break;
		y+=t;
		if(y==n+1)
		{
			t=-1;
			x++;
			y=n;
		}
		if(y==0)
		{
			t=1;
			x++;
			y=1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
