#include <iostream>
using namespace std;
const int maxn=510, mod=998244353;
int n, m;
string s;
int c[maxn], d[maxn], e[maxn];
int ans=0;
void dfs(int x)
{
	if(x==n)
	{
		int fail=0,ok=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0'||fail>=c[d[i]]) fail++;
			else if(s[i]=='1') ok++;
		}
		if(ok>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=0;i<n;++i)
	{
		if(e[i]) continue;
		d[x]=i, e[i]=1;
		dfs(x+1);
		e[i]=0;
	}
}
int pc=0;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;++i) {
		cin>>c[i];
		pc+=s[i]-'0';
	}
	if(pc==n) {
		ans=1;
		for(int i=2;i<=n;i++) ans=(ans*i)%mod;
	} else if (pc < m) {
		ans=0;
	} else if(n<=10) {
		dfs(0);
	}
	
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
}
