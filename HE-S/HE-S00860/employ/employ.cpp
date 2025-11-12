#include<bits/stdc++.h>
using namespace std;
const int QAQ=510;
#define ll long long
const ll mo=998244353;
int n,m,ans;
char s[QAQ];
int c[QAQ];
int p[QAQ];
bool vis[QAQ];
void dfs(int x)
{
	if(x>n)
	{
		int mei=0,ke=0;
		for(int i=1;i<=n;i++)
		{
			int nw=p[i];
			if(mei>=c[nw])
			{
				mei++;
			}
			else if(s[i]=='0')
			{
				mei++;
			}
			else ke++;
		}
		if(ke>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		p[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
	
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}
/*

3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3




计数 DP 题。

思考清楚 DP 顺序和 DP 含义。

性质 1 ：我们只关心录用的人数，也就是我们可以按 c 排序后 DP，根据单调性 DP。

n<=500。 


等待思考 1 ：我们的排列实际上是让我们钦定一个录取顺序。 

把 c 从小到大排序：
哎我又读错题了，他钦定好了录取的规律。
 



枚举排列。 
n!
8pts

m=1？ 


我们发现每个人能否被录取与他是否是 0 和他前面的 0 是否超过 c_i 有关。

f[S][i]：选择了 S 集合内的人，i 个人被录取的方案数。

g[S][i][j]：选择了 S 集合内的人，

---

A 性质：
直接按 c 从小到大排序。 
f[i][j]：[1,i] 的人有 j 个 


不会啊 



*/
