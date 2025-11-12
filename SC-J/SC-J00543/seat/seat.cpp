#include <bits/stdc++.h>
using namespace std;
int n,m,s;
struct node
{
	int g,id;
}a[110];
bool cmp(node a,node b)
{
	return a.g>b.g;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int x;
		cin>>x;
		a[i].g=x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			s=i;
			break;
		}
	}
	int x,y;
	y=(s-1)/n+1;
	if(y&1)x=(s-1)%n+1;
	else x=n-(s-1)%n;
	cout<<y<<' '<<x;
	return 0;
}