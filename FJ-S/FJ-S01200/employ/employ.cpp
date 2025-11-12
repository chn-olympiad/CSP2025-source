#include<bits/stdc++.h>
using namespace std;
long long n,m,z[501],a[501],vis[11],d[11],ans=0,mod=998244353,x[501],y[501];
string s;
long long qpow (long long a,long long b,long long mo)
{
	long long aa=a,ans=1;
	while (b>0)
	{
		if (b%2==1) ans=(ans*aa)%mod;
		aa=(aa*aa)%mod;
		b/=2;
	}
	return ans;
}
bool p ()
{
	long long cnt=0,an=0;
	for (int i=1;i<=n;i++) 
	{
		if (cnt>=a[d[i]]) 
		{
			cnt++;
			continue;
		}
		if (z[i]==0)
		{
			cnt++;
			continue;
		}
		an++;
	}
	if (an<m) return 0;
	return 1;
}
void dfs (int ss)
{
	if (ss==n+1)
	{
		if (p()) ans++;
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[i]) continue;
		vis[i]=1;
		d[ss]=i;
		dfs(ss+1);
		vis[i]=0;
	}
}
void zxy ()
{
	dfs(1);
	cout<<ans<<endl;
	exit(0);
}
int main ()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	cin>>s;
	x[0]=1;
	for (int i=1;i<=n;i++) x[i]=x[i-1]*i%mod;
	for (int i=0;i<=n;i++) y[i]=qpow(x[i],mod-2,mod);
	for (int i=0;i<s.size();i++) z[i+1]=(long long)(s[i]-'0');
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n<=10) zxy();
	else cout<<0;
	return 0;
}
