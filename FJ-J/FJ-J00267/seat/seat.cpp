#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[105],b;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%lld",&a[i]);
	b=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
		if(a[i]==b)
		{
			b=i;
			break;
		}
	b=n*m-b+1;
	int x=b/n+1;
	int y=b%n;
	if(y==0)
	{
		x--;
		y=n;
	}
	if(x%2==0)y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}
