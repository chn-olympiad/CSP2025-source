#include <iostream>
#include <algorithm>
using namespace std;
namespace GY2025YY
{
	const int N=1000;
	int n,m,c[N];
	char s[N];bool f[N];
	long long ans=0;
	inline void dfs(int id,int cnt,int fcnt)
	{
		if (fcnt>n-m) return;
		if (id>n)
		{
			if (cnt>=m) ++ans;
			return;
		}
		for (int i=1;i<=n;++i)
		{
			if (f[i]) continue;
			f[i]=true;
			if (fcnt>=c[i] || s[id]=='0') dfs(id+1,cnt,fcnt+1);
			else dfs(id+1,cnt+1,fcnt);
			f[i]=false;
		}
	}
	int main()
	{
		freopen("employ.in", "r", stdin);
		freopen("employ.out","w",stdout);
		scanf("%d%d%s",&n,&m,s+1);
		for (int i=1;i<=n;++i)
			scanf("%d",c+i);
		sort(c+1,c+n+1);
		dfs(1,0,0);
		printf("%lld",ans);
		return 0;
	}
}
int main()
{
	return GY2025YY::main();
}

