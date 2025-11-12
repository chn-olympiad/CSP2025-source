#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;

const int MAXN=500+5,MOD=998244353;
int n,m,a[MAXN],ans,b[MAXN],c[MAXN];
string s;

void dfs(int k)
{
	if(k>n)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[c[i]]<=cnt || s[i-1]=='0') cnt++;
		}
		if(n-cnt>=m) ans++;
		if(ans==MOD) ans=0;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]) continue;
		c[k]=i;b[i]=1;
		dfs(k+1);
		c[k]=0;b[i]=0;
	}
}

int main()
{
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=1;
	for(int i=0;i<n;i++) if(s[i]=='0') flag=0;
	if(m==n) 
	{
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=(a[i]==0);
		if(flag && cnt==0) 
		{
			ll sum=1;
			for(int i=1;i<=n;i++) sum=sum*i%MOD;
			cout<<sum<<endl; 
		}
		else cout<<0<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
//by Matrix_Power

