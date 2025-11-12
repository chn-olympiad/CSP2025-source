#include<bits/stdc++.h>
#define ll long long
#define pib pair<int,bool>
#define f first
#define s second
using namespace std;
int n,m,x=1,y=1;
pib a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i].f);
	a[1].s=1;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--)
	{
		if(a[i].s)
		{
			printf("%d %d",y,x);
			return 0;
		}
		if(y%2==1)
		{
			if(x==n) y++;
			else x++;
		}
		else
		{
			if(x==1) y++;
			else x--;
		}
	}
	return 0;
}
