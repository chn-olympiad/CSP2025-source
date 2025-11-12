#include<bits/stdc++.h>
#define ll long long
#define db double
#define int ll//#
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int inf=2e9;
const db eps=1e-7;
int n,m,c[505],a[505],t[505],ans;
string s;
void dfs(int u)
{
	if(u>n)
	{
		int p=0,l=0;
		for(int i=1;i<=n;i++)
		{
			if(p>=c[a[i]]||s[i-1]=='0')p++;
			else l++;
		}
		if(l>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!t[i])
		{
			a[u]=i;
			t[i]=u;
			dfs(u+1);
			t[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	bool spe=true;
	for(auto u:s)
	{
		if(u=='0')
		{
			spe=false;
			break;
		}
	}
	if(spe)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*1ll*i;
			ans=ans%998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

