#include <iostream>
#include <queue>
#include <algorithm>

const int N = 1e5 + 5;

struct node
{
	int a1,a2,a3;
}a[N];
bool cmp2(node x,node y)
{
	return x.a2 - x.a1 < y.a2 - y.a1;
}

int n;
int ty[N];
int fans;
void dfs(int pos,int n1,int n2,int n3)
{
	if(pos > n)
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(ty[i] == 1)
				ans += a[i].a1;
			if(ty[i] == 2)
				ans += a[i].a2;
			if(ty[i] == 3)
				ans += a[i].a3;
		}
		fans = std::max(fans,ans);
	}
	if(n1 < n / 2)
	{
		ty[pos] = 1;
		dfs(pos + 1,n1 + 1,n2,n3);
		ty[pos] = 0;
	}
	if(n2 < n / 2)
	{
		ty[pos] = 2;
		dfs(pos + 1,n1,n2 + 1,n3);
		ty[pos] = 0;
	}
	if(n3 < n / 2)
	{
		ty[pos] = 3;
		dfs(pos + 1,n1,n2,n3 + 1);
		ty[pos] = 0;
	}
}
void solve1()
{
	fans = 0;
	dfs(1,0,0,0);
	printf("%d\n",fans);
}

void solve2()
{
	std::sort(a + 1,a + n + 1,cmp2);
	int ans = 0;
	for(int i = 1;i <= n / 2;i ++)
		ans += a[i].a1;
	for(int i = n;i > n / 2;i--)
		ans += a[i].a2;
	printf("%d\n",ans);
}

void init()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
}

int main(void)
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = 0;
	scanf("%d",&T);
	
	while(T--)
	{
		init();
		bool flag = true;
		for(int i = 1;i <= n;i++)
			if(a[i].a3) flag = false;
		if(flag) solve2();
		else solve1();
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
