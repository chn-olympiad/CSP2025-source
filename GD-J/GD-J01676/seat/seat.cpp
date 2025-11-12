#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10086],cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
	}
	int as=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n;i>=1;i--)
	{
		if(i%2==0)
		{
			for(int j=1;j<=m;j++)
			{
				cnt++;
				if(a[cnt]==as)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else if(i%2==1)
		{
			for(int j=m;j>=1;j--)
			{
				cnt++;
				if(a[cnt]==as)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
}
