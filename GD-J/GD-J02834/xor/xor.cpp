#include<bitset>
#include<cstdbool>
#include<cstdio>
#include<cstring>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
int n,k,a[500001],sum[500001][25],ans,up=1e9,ma;
bool check(int x,int y)
{
	for(int l=0;l<=20;l++)
	{
		if(((sum[y][l]-sum[x-1][l])&1)!=(bool)(k&(1<<l)))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=0;j<=20;j++)
		{
			sum[i][j]=sum[i-1][j];
			if(a[i]&(1<<j)) sum[i][j]++;
		}
	}
	for(int I=1;I<=MIN(n,top-1);I++)
	{
		ans=0;
		for(int i=I;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(check(i,j))
				{
					if(up==1e9) up=j;
					ans++;
					i=j;
					break;
				}
			}
		}
		ma=MAX(ma,ans);
	}
	printf("%d",ma);
}
