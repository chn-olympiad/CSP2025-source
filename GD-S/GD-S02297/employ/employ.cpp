#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::string;

const int MOD = 998244353;
int n,m,c[505],used[25];
bool vis[25];
long long pre[505] = {1},ans;
string s;

long long quick_pow(long long a,int b){
	if(b % 2 == 0)
	{
		if(b == 0)
		{
			return 1;
		}
		long long t = quick_pow(a,b / 2);
		return t * t % MOD;
	}
	if(b != 1)
	{
		return a * quick_pow(a,b - 1) % MOD;
	}
	return a;
}

void dfs(int k){
	if(k > n)
	{
		int cnt = 0;
		for(int i = 1;i <= n;i += 1)
		{
			if(s[i] == '1' && c[used[i]] > i - cnt - 1)
			{
				cnt += 1;
			}
			if(cnt >= m)
			{
				ans += 1;
				ans %= MOD;
				break;
			}
		}
	}
	else
	{
		for(int i = 1;i <= n;i += 1)
		{
			if(!vis[i])
			{
				used[k] = i;
				vis[i] = true;
				dfs(k + 1);
				vis[i] = false;
			}
		}
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	bool A = true;
	cin>>n>>m>>s;
	s = "L" + s;
	for(int i = 1;i <= n;i += 1)
	{
		pre[i] = pre[i - 1] * i % MOD;
		cin>>c[i];
		if(s[i] == '0')
		{
			A = false;
		}
	}
	if(n <= 18)
	{
		dfs(1);
		cout<<ans;
	}
	else if(m == n)
	{
		bool flag = true;
		for(int i = 1;i <= n;i += 1)
		{
			if(s[i] == '0' || c[i] == 0)
			{
				flag = false;
				cout<<0;
				break;
			}
		}
		if(flag)
		{
			cout<<pre[n];
		}
	}
	else if(m == 1)
	{
		int idx = -1,cnt = 0;
		for(int i = 1;i <= n;i += 1)
		{
			if(s[i] == '1')
			{
				idx = i;
				break;
			}
		}
		if(idx == -1)
		{
			cout<<0;
		}
		else
		{
			for(int i = 1;i <= n;i += 1)
			{
				if(c[i] > idx)
				{
					cnt += 1;
				}
			}
		}
		cout<<cnt * pre[n - 1] % MOD;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
