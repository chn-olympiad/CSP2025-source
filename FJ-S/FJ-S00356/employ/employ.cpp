#include<iostream>
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 998244353,
M = 1e3 +5;
const int N = 5e5 + 5;
string s1,s;
int n,m,ans,c[M];
int vis[M],a[M];
int f[N][20][20];
int ve[N];
//f(s,i,j)
//s代表已用子集，i代表当前为第i位,
//j代表已录用人数 

void solve()
{
	int cnt = 0,sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(cnt >= c[a[i]] || s[i - 1] == '0')
			cnt++;
		else sum++;
	}
	ans = (ans + (sum >= m)) %mod;
}

void dfs(int l)
{
	if(l == n + 1)
	{
		solve();
		//for(int i = 1; i <= n; i++)
		//	cout << a[i] << " ";
		//cout << "\n";
		return ;
	}
	for(int i = 1; i <= n; i++)
		if(!vis[i])
		{
			vis[i] = 1;
			a[l] = i;
			dfs(l +1);
			vis[i] = 0;
		}
}

int count(int n)
{
	int sum = 0;
	while(n) 
		sum += n & 1, n>>= 1;
	return sum;
}

void add(int &a,int b)
{
	a = (a + b) % mod;
}
/*
int cmp(int x,int y)
{
	return count(x) < count(y);
}
*/
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m >> s; s1 = " " + s;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	
	if(n <= 12)
	{
		//cout << n << "\n";
		dfs(1);
		//int ans = 1;
		//for(int i = 1; i <= n; i++)
		//	ans = ans *i % mod;
		cout << ans;
		return 0;
	}
	
	//int mx = (1 << n);
	//for(int s = 0; s < (1 << n); s++)
	//	ve[s] = s;
	//sort(ve,ve + mx,cmp);
	
	f[0][0][0] = 1; //s1 += " ";
	//cout << s1;
	for(int s = 0; s < (1 << n); s++)
	{
		//int s = ve[l];
		int k = count(s);
		//cout << k <<"\n";
		for(int j = 0; j <= k; j++)
		{
			for(int i = 1; i <= n; i++)
			{
				if(s >> (i - 1) & 1) continue;
				if(s1[k + 1] == '0' || k - j >= c[i])
					add(f[s | (1 << (i - 1))][k + 1][j],
					f[s][k][j]);
				else
					add(f[s | (1 << (i - 1))][k + 1][j + 1],
					f[s][k][j]);		
			}
		}
	}
	
	for(int s = 0; s < (1 << n); s++)
	{
		int k = count(s);
		for(int j = 0; j <= k; j++)
			if(j >= m) add(ans,f[s][k][j]); 
			//cout << s << " " << k << " " << j << " " << f[s][k][j] << "\n";
	}
	cout << ans;
}
