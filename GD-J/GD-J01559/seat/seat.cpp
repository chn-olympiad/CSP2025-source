#include<bits/stdc++.h>
using namespace std;
int a[110];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int x=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int now=0;
	for(int i=1;i<=n*m;i++)if(a[i]==x)
	{
		now=i;
		break;
	}
	int ansx=0,ansy=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				cnt++;
				if(cnt==now)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				cnt++;
				if(cnt==now)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
ÎÒµÄÊÖÍó°¡ 
*/
