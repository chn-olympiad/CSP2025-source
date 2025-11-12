#include <iostream>
#include <algorithm>
using namespace std;
namespace GY2025YY
{
	const int N=20;
	int n,m,a[N*N],ans[N][N];
	inline bool cmp(int x,int y)
	{
		return x>y;
	}
	int main()
	{
		freopen("seat.in", "r", stdin);
		freopen("seat.out","w",stdout);
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n*m;++i)
			scanf("%d",a+i);
		int x,y,tmp=a[1];
		sort(a+1,a+n*m+1,cmp);
		for (int i=1;i<=n*m;++i)
		{
			if (a[i]==tmp)
			{
				y=(i+n-1)/n;
				if (y&1) x=(i%n==0?n:i%n);
				else x=n-(i%n==0?n:i%n)+1;
				printf("%d %d",y,x);
				return 0;
			}
		}
		return 0;
	}
}
int main()
{
	return GY2025YY::main();
}

