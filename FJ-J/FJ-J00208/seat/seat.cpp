#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	int t=1;
	sort(b+1,b+n*m+1);
	reverse(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[1]==b[i])
		{
			t=i;
			break;
		}
	}
	printf("%d %d",(t+n-1)/n,((((t+n-1)/n)&1)?((t-1)%n+1):m-(t-1)%n));
	return 0;
}
