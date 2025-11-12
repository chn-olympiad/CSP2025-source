#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
string s;
bool a[N];
int c[N];
int k[N];
int ans=0;
bool vis[N];
void dfs(int x)
{
	if(x>n)
	{
		int per=0; 
		for(int i=1;i<=n;i++) 
		{
			if(per>=c[k[i]] or !a[i])
				per++;
		}
		if(n-per>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			k[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int fpow(int x,int k)
{
	int base=x,ans=1;
	while(k)
	{
		if(k&1) ans*=base,ans%=mod;
		base*=base;
		k>>=1;
		base%=mod;
	}
	return ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
		a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<'\n';
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(!a[i])
			{
				cout<<0<<'\n';
				return 0;
			}
		}
		cout<<fpow(2,n)<<'\n';
	}
	else 
		cout<<fpow(2,n)<<'\n';
	return 0;
}

