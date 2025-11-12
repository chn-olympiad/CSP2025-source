#include<cstdio>
using namespace std;
const int N=15;
int n,m,a[N*N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int num=1;
	for(int i=2;i<=n*m;i++)
		if(a[i]>a[1]) num++;
	for(int j=1;j<=m;j++)
	{
		if(j%2)
		{
			for(int i=1;i<=n;i++)
			{
				num--;
				if(num==0)
				{
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				num--;
				if(num==0)
				{
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
	}
	return 0;
}
