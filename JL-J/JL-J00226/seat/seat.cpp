#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a,id;
}o[1145141];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>o[i].a,o[i].id=i;
	sort(o+1,o+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(o[i].id==1)
		{
			int y=(i-1)/n;
			y++;
			int x;
			x=i-(y-1)*m;
			if(!(y&1))x=n-x+1;
			cout<<y<<' '<<x;
			break;
		}
	}
	return 0;
}
