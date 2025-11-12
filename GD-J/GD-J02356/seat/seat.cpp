#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=1,y=1,d=0;
	int flag=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==flag)
		{
			cout<<y<<' '<<x;
			return 0;
		}
		if((x==n&&d==0)||(x==1&&d==1))
		{
			y++;
			d^=1;
		}
		else if(d==0)
		{
			x++;
		}
		else if(d==1)
		{
			x--;
		}
	}
	return 0;
}
