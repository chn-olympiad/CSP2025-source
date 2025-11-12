#include <bits/stdc++.h>
using namespace std;
int read()
{
	int res = 0,f = 1;
	char ch = getchar();
	while (ch<'0'||ch>'9') f = (ch=='-'?-f:f),ch = getchar();
	while (ch>='0'&&ch<='9') res = (res<<3)+(res<<1)+(ch^48),ch = getchar();
	return res*f;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writech(int x,char ch){write(x),putchar(ch);}
const int N = 505,MOD = 998244353;
int n,m;
int s[N];
int c[N];
int ans;
bool vis[N];
void dfs(int x,int lu)
{
	if (x>n&&lu>=m){ans=(ans+1)%MOD;return ;}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			int wl = x-lu;
			vis[i]=true;
			if (wl>c[i]||s[x]==0) dfs(x+1,lu);
			else dfs(x+1,lu+1);
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string ss;cin>>ss;
	for (int i = 1; i <= n; i++) s[i]=ss[i-1]-'0';
	for (int i = 1; i <= n; i++) cin>>c[i];
	if (n<=11)
	{
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	if (m==n)
	{
		int ans = 1;
		for (int i = 1; i <= n; i++) ans=ans*i%MOD;
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			if (s[i]==0||c[i]==0)
			{
				flag=false;
				break;
			}
		}
		if (!flag) cout<<1;
		else cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

