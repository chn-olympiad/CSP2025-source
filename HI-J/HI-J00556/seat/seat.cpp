#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],a1,ii=1,jj=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a1);
	for(int i=2;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+2,a+n*m+1);
	for(int i=0;i<=n*m;)
	{
		while(ii<=n&&i<=n*m)
		{
			i++;
			if(a1>a[n*m-i+1]||i==n*m)
			{
				printf("%d %d\n",jj,ii);
				return 0;
			}
			ii++;
		}
		jj++;
		ii=n;
		i++;
		if(a1>a[n*m-i+1]||i==n*m)
		{
			printf("%d %d\n",jj,ii);
			return 0;
		}
		while(ii>1&&i<=n*m)
		{
			i++;
			ii--;
			if(a1>a[n*m-i+1]||i==n*m)
			{
				printf("%d %d\n",jj,ii);
				return 0;
			}
		}
		jj++;
		ii=1;
		i++;
		if(a1>a[n*m-i+1]||i==n*m)
		{
			printf("%d %d\n",jj,ii);
			return 0;
		}
	}
	return 0;
}
