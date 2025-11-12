#include <bits/stdc++.h>
#define O 205
using namespace std;
int T,n;
struct node
{
	int a,b,c;
}	lst[O];
bool cmp(node n1,node n2)
{
	return n1.a > n2.a;
}
int dfs(int idx,int a,int b,int c,int sum)
{
	if(idx == n + 1)
		return sum;
	int ans = 0;
	if(a < n / 2)
		ans = max(ans,dfs(idx + 1,a + 1,b,c,sum + lst[idx].a));
	if(b < n / 2)
		ans = max(ans,dfs(idx + 1,a,b + 1,c,sum + lst[idx].b));
	if(c < n / 2)
		ans = max(ans,dfs(idx + 1,a,b,c + 1,sum + lst[idx].c));
	return ans;	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 1;i <= n;++i)
			scanf("%d %d %d",&lst[i].a,&lst[i].b,&lst[i].c);
		sort(lst + 1,lst + 1 + n,cmp);
		if(n <= 30)
			printf("%d\n",dfs(1,0,0,0,0));
		else
		{
			int sum = 0;
			for(int i = 1;i <= n / 2;++i)
				sum += lst[i].a;
			printf("%d\n",sum);
		}
	}
	return 0;	
}
/*
不难看出,这应当是一个有限制的dp
本题的主要问题就是如何处理这个某个部门分配的人数不超过n / 2 


我们先思考如何定义状态
结合n <= 1e5,应该是线性dp
如何定义状态?
首先,我们最难状态转移的一点是,如果我们后面发现某个部门安插另外一个人的贡献更大,我们是没办法修改的
所以我们只能在定义dp状态的时候就把每个部门的最优解记录下来
定义dp[i][k]为截止到第i个人,当前人数最多的部门有k个人,所能取得的最大价值 
 


*/
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
