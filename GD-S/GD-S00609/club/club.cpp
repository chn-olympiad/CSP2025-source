#include <cstdio>
#include <algorithm>
using namespace std;

int t,n,cnt = 0;
int a[4][100010];

void solve1()
{
	sort(a[1]+1,a[1]+1+n);
	int s = n,g = n/2;
	while(g--)
	{
		cnt+=a[1][s--];
	}
}

int main()
{
	freopen("club5.in","r",stdin);
	freopen("club5.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				scanf("%d",&a[j][i]);
			}
		}
		solve1();
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
