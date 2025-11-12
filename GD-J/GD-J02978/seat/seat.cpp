#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int past,tru;
}a[100101];
bool cmp(node x,node y)
{
	return x.tru>y.tru;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i].tru);
		a[i].past=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].past==1)
		{
			int x=i,y=i;
			y%=n;
			x/=n;
			x++;
			if(y==0)
			{
				x--;
				y=n;
			}
			printf("%lld ",x);
			if(x%2==1)
				printf("%lld",y);
			else printf("%lld",n-y+1);
			break;
		}
	}
	return 0;
}
