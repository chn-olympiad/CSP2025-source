#include <iostream>
#include <algorithm>
using namespace std;
namespace GY2025YY
{
	const int N=5003,MOD=998244353;
	int n,a[N],dp[N][4],C[N][N];
	inline bool cmp(int x,int y)
	{
		return x>y;
	}
	inline void funC()
	{
		C[0][0]=1;
		for (int i=1;i<=n+1;++i)
		{
			for (int j=1;j<=i;++j)
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
		}
	}
	int main()
	{
		freopen("polygon.in", "r", stdin);
		freopen("polygon.out","w",stdout);
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",a+i);
		funC();long long ans=0;
		for (int i=3;i<=n;++i)
			ans=(ans+C[n+1][i+1])%MOD;
		printf("%lld",ans);
		return 0;
	}
}
int main()
{
	return GY2025YY::main();
}

