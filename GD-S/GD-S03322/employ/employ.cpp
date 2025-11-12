#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const ll Mod=998244353;

int n, m, a[N], c[N], cnt1=0;
ll ans=0;
char s[N];
int vis[N], cho[N];
void dfs(int dep)
{
	if (dep>n)
	{
		int sum=0;
		for (int i=1; i<=n; i++) 
			if (sum>=c[cho[i]] || a[i]==0) sum++;
		
		if (sum<=n-m) 
		{
//			for (int i=1; i<=n; i++) printf("%d ", cho[i]);
//			puts("");
			ans++;
			if (ans>=Mod) ans-=Mod;
		}
		return ;
	}
	
	for (int i=1; i<=n; i++)
		if (!vis[i])
		{
			cho[dep]=i, vis[i]=1;
			dfs(dep+1);
			vis[i]=0;
		}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d%s", &n, &m, s+1);
	for (int i=1; i<=n; i++) scanf("%d", &c[i]);
	for (int i=1; i<=n; i++) a[i]=s[i]-'0';
	
	for (int i=1; i<=n; i++) cnt1+=a[i];
	if (cnt1<m)
	{
		printf("0");
		return 0;
	}
	if (n<=10)
	{
		dfs(1);
		printf("%lld", ans);
		return 0;
	}
	if (cnt1==n)
	{
		ans=1;
		for (int i=1; i<=n; i++) ans=ans*i%Mod;
		printf("%lld", ans);
		return 0;
	}
	return 0;
}
/*
4 2
1111
0 1 2 3
*/
