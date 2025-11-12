#include <bits/stdc++.h>
using namespace std;
int n;
int T;
int a[100010],b[100010],c[100010];
long long ans;
int N = 1e5+10;
int ca,cb,cc;
long long answer = -1;
void dfs(int i)
{
	if(i == n+1)
	{
		answer = max(answer,ans);
		return ;
	}
	if(ca < n/2)
	{
		ca++;
		ans += a[i];
		dfs(i+1);
		ans -= a[i];
		ca--;
	}
	if(cb < n/2)
	{
		cb++;
		ans += b[i];
		dfs(i+1);
		ans -= b[i];
		cb--;
	}
	if(cc < n/2)
	{
		cc ++;
		ans += c[i];
		dfs(i+1);
		ans -= c[i];
		cc--;
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
			scanf("%d%d%d",&a[j],&b[j],&c[j]);
		dfs(1);
		printf("%lld\n",answer);
		answer = 0;
		ans = 0;
	}
	return 0;
}
2
10
1 0 0
2 0 0
3 1 1
4 1 1
5 1 1
6 1 1
7 1 1
8 1 1
9 1 1
10 1 1
