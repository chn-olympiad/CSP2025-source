#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int a[110];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1],sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(p==a[i])
		{
			p=i;
			break;
		}
	int x=1,y=1;
	for(int i=1;i<p;i++)
	{
		if((x%2&&y==n)||(x%2==0&&y==1))
		{
			x++;
			continue;
		}
		if(x%2) y++;
		else y--;
	}
	cout<<x<<' '<<y;
	return 0;
}
