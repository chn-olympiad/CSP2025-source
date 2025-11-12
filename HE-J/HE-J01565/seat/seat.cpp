#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define unsigned long long ull;
int n,m,a[110],ans[15][15];
bool cmp(int x,int y){return x > y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n * m;i ++)
		scanf("%d",&a[i]);
	int num = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	int sum = 1;
	for(int i = 1;i <= n;i ++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1;j <= m;j ++)
			{
				ans[i][j] = a[sum];
				sum ++;
			}
		}
		else
		{
			for(int j = m;j >= 1;j --)
			{
				ans[i][j] = a[sum];
				sum ++;
			}
		}
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			if(ans[i][j] == num)
			{
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
