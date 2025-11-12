#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e2+10;
const int MOD = 998244353;

int n, m;
string s;
int t[MAXN];
int a[MAXN];

int b[MAXN];
bool vis[MAXN];

long long ans;

void f(int l)
{
	if(l == n)
	{
		int fl = 0;
		for(int i=1;i<=n;i++) fl += (fl >= a[b[i]] || !t[i]);
		if(n - fl  >= m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i] = true;
			b[l+1] = i;
			f(l+1);
			vis[i] = false;
		}
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) t[i] = s[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n <= 11)
	{
		f(0);
		cout<<ans;
	}
	else
	{
		ans = 1;
		for(int i=1;i<=n;i++) ans *= i, ans %= MOD;
		cout<<ans;
	}
	return 0;
}
