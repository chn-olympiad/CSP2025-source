#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],b[505],add;
long long ans;
string s;
void dfs(int cnt,int pass)
{
	if(cnt==n) 
	{
		if(pass>=m) ans=(ans+1)%mod;
		return;
	}
	for(register int i=1;i<=n;++i)
	{
		if(b[i]!=0) continue;
		if(cnt-pass>=c[i]||s[cnt]=='0') b[i]=1,dfs(cnt+1,pass),b[i]=0;
		else b[i]=1,dfs(cnt+1,pass+1),b[i]=0; 
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(register int i=1;i<=n;++i) cin>>c[i];
	if(n<=18)
	{
		dfs(0,0);
		cout<<ans;
		return 0;
	}
	else if(m==1)
	{
		int x=1e9+5;
		for(register int i=0;i<s.size();++i)
			if(s[i]=='1') { x=i; break; }
		for(register int i=1;i<=n;++i)
			if(c[i]>x) add++;
		if(add==0) { cout<<0; return 0; }
		ans=1;
		for(register int i=1;i<n;++i) ans=(ans*i)%mod;
		cout<<(ans*add)%mod;
	}
	else if(m==n)
	{
		for(register int i=0;i<s.size();++i)
			if(s[i]=='0') add=-1;
		if(add==-1) { cout<<0; return 0; }
		ans=1;
		for(register int i=1;i<=n;++i) ans=(ans*i)%mod;
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
