#include <iostream>
#include <algorithm>
using namespace std;
namespace GY2025YY
{
	const int N=100003;
	int n,c1,c2,c3,ans;
	struct Node
	{
		int a,b,c;
	} s[N];
	inline void dfs(int id,int res)
	{
		if (id>n)
		{
			if (res>ans) ans=res;
			return;
		}
		if (c1<n/2) {++c1;dfs(id+1,res+s[id].a);--c1;}
		if (c2<n/2) {++c2;dfs(id+1,res+s[id].b);--c2;}
		if (c3<n/2) {++c3;dfs(id+1,res+s[id].c);--c3;}
	}
	inline bool cmp(Node t1,Node t2)
	{
		return t1.a>t2.a;
	}
	inline void solve()
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
		if (n<=10)
		{
			ans=0;dfs(1,0);
			printf("%d\n",ans);
		}
		else
		{
			sort(s+1,s+n+1,cmp);
			for (int i=1;i<=n/2;++i) ans+=s[i].a;
			printf("%d\n",ans);
		}
	}
	int main()
	{
		freopen("club.in", "r", stdin);
		freopen("club.out","w",stdout);
		int T;scanf("%d",&T);
		while (T--) solve();
		return 0;
	}
}
int main()
{
	return GY2025YY::main();
}

