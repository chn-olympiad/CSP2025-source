#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N=520;
const int mod=998244353;

int n,m;
string s;
int c[N];
int f[N];
int p[N],ans;
bool vis[N];

void init()
{
	f[0]=1;
	for(int i=1;i<N;i++) f[i]=f[i-1]*i%mod;
}

void check()
{
	int sum=0;
	for(int i=1;i<=n;i++)
	  if(i-1-sum<p[i]&&s[i-1]=='1')
	    sum++;
	if(sum>=m) ans++;
}

void dfs(int d)
{
	if(d>n)
	{
		check();
		return ;
	}
	
	for(int i=1;i<=n;i++)
	if(!vis[i])
	{
		vis[i]=1,p[d]=c[i];
		dfs(d+1);
		vis[i]=0;
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	init();
	cin>>n>>m;
	cin>>s;
	int first1=0;
	while(first1<n&&s[first1]=='0') first1++;
	if(first1==n)
	{
		cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n;i++) cin>>c[i];
	
	if(m==n)
	{
		for(int i=0;i<n;i++)
		if(s[i]=='0'||c[i]==0)
		{
			cout<<0;
			return 0;
		}
		cout<<f[n];
		return 0;
	}
	
	if(n<=10)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
