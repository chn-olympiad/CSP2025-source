#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ioimprove(); ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE(x); freopen(x".in","r",stdin);freopen(x".out","w",stdout);
int n,a[5005],inv[5005],mul[5005],cnt,vis[25];
const int mod = 998244353;
int qpow(int a,int b)
{
	if(b == 0) return 1;
	if(b == 1) return a;
	int res = qpow(a,b / 2);
	if(b & 1) return ((res * res) % mod * a) % mod;
	return res * res % mod;
}
void init()
{
	mul[1] = inv[1] = 1;
	for(int i = 2;i <= 5000;i++) mul[i] = (mul[i - 1] * i) % mod,inv[i] = qpow(mul[i],mod - 2);
}
int C(int n,int m)
{
	return ((mul[n] * inv[n - m]) % mod * inv[m]) % mod;
}
void dfs(int maxid,int sum,int step,int last)
{
	if(sum > 2 * a[maxid] && step >= 3) cnt++;
	for(int i = last + 1;i <= n;i++)
		if(!vis[i])
		{
			vis[i] = 1;
			if(i > maxid) dfs(i,sum + a[i],step + 1,i);
			else dfs(maxid,sum + a[i],step + 1,i);
			vis[i] = 0;
		}
}
signed main()
{
	FILE("polygon");
	ioimprove();
	init();
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	if(n == 3)
	{
		if(a[1] + a[2] > a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[n] == 1)
	{
		int sum = 0;
		for(int i = 3;i <= n;i++) sum = (sum + C(n,i)) % mod;
		cout<<sum;
		return 0;
	}
	if(n <= 20)
	{
		dfs(0,0,0,0);
		cout<<cnt;
		return 0;
	}
	
	return 0;
}
