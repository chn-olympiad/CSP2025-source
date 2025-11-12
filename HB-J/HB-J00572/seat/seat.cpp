#include <bits/stdc++.h>
using namespace std;
struct point
{
	int a,b;
}a[105];
bool cmp(point x,point y)
{
	return x.a>y.a;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].a;
		a[i].b=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].b==1)
		{
			if(((i-1)/n+1)%2==1)
			{
				cout<<(i-1)/n+1<<' '<<(i-1)%n+1;
			}
			else
			{
				cout<<(i-1)/n+1<<' '<<(n+1-i%n);
			}
			break;
		}
	}
	return 0;
}
