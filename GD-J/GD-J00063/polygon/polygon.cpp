#include <bits/stdc++.h>
using namespace std;

const int q = 998244353;

int n;
int a[5010];
int b[5010],lb;
int ret,ans;

void dfs(int l,int u,int mn,int sm)
{
	if (lb == l)
	{
		if (sm > 2 * mn)
		{
			ret = (ret + 1) % q;
		}
		return ;
	}
	for (int i = u + 1;i <= n;i++)
	{
		b[++lb] = a[i];
		dfs(l,i,max(mn,a[i]),sm + a[i]);
		b[lb--] = 0;
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
	{
		ret = 0;
		dfs(i,0,0,0);
		ans = (ans + ret) % q;
	}
	printf("%d\n",ans);
	return 0;
}
