#include<bits/stdc++.h>
using namespace std;
#define N 510
#define mod 998244353
int n,m,c[N],x[N];
int ans;
string s;
bool vis[N];
void dfs(int w)
{
	if(w==n+1)
	{
		int now=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
				now++;
			else
				if(now>=c[x[i]]) now++;
		}
		if(n-now>=m) 
		{
			ans++;
//			for(int i=1;i<=n;i++) cout<<p[i]<<
		 } 
		return;	
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			x[w]=i;
			dfs(w+1);
			vis[i]=0;
		}
	}
 } 
bool pd()
{
	for(int i=1;i<=n;i++)
		if(s[i]!='1') return 0;
	return 1;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(pd())
	{
		long long ans=1;
		for(int i=2;i<=n;i++) ans=ans*i%mod;
		return cout<<ans,0;
	}
	dfs(1);
	cout<<ans;
}

