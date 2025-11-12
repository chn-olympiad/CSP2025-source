#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch))
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return x;
}

const int MAXN = 505;
const int MOD = 998244353;

int n , m;

int s[MAXN];

int c[MAXN];

long long ans;

bool vis[MAXN];

void dfs(int pos , int num)
{
	if(pos == n)
	{
		if(num >= m)ans++;
		ans %= MOD;
		return;
	}
	
//	cout << pos << " " << num << endl;
	
	for(int i = 1;i <= n;i++)
	{
		if(vis[i])continue;
		vis[i] = 1;
		dfs(pos + 1 , num + (s[pos + 1] && (pos - num < c[i])));
		vis[i] = 0;
	}
}

int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	
	n = read();
	m = read();
	
//	cout << 1 << endl;
	
	for(int i = 1;i <= n;i++)
	{
		char ch = getchar();
		while(!isdigit(ch))ch = getchar();
		s[i] = ch - '0';
	}
	
	for(int i = 1;i <= n;i++)c[i] = read();
	
	dfs(0 , 0);
	
	printf("%lld\n" , ans % MOD);
	
	return 0;
}