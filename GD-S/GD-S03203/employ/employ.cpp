#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
	ll ret = 0 ,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -f : f) ,ch = getchar();
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0' ,ch = getchar();
	return ret * f;
}

int n ,m ,ans;
const int mod = 998244353;
const int N = 510;
int c[N] ,a[N] ,vis[N];
char s[N];

void dfs(int d)
{
	if (d > n)
	{
		int now = 0;
		for (int i = 1;i <= n;i++)
		{
			if (now >= c[a[i]]) now++;
			else now += (s[i] == '0');
		}
		ans += (now <= n - m);
		return ;
	}
	for (int i = 1;i <= n;i++)
		if (!vis[i])
		{
			a[d] = i ,vis[i] = 1;
			dfs(d + 1);
			vis[i] = 0;
		}
}

void solve1()
{
	dfs(1);
	printf("%d\n",ans);
}

void solve2()
{
	ll ans = 1;
	for (int i = 1;i <= n;i++) ans = ans * i % mod;
	printf("%lld\n",ans);
}

int main()
{
	freopen("employ.in" ,"r" ,stdin);
	freopen("employ.out" ,"w" ,stdout);
	n = read() ,m = read();
	
	scanf("%s",s + 1);
	for (int i = 1;i <= n;i++) c[i] = read(); 
	
	if (n <= 10) solve1();
	else solve2();
	
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/

