#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=505,mod=998244353;
ll n,m,a[N],ans,b[N];
string s;
bool v[N];
void dfs(ll x,ll s)
{
	if(x>n)
	{
		ans=(ans+(n-s>=m))%mod;
		return;
	}
	if(n-s<m)
	{
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(!v[i])
		{
			if(s>=a[i]||b[x])
			{
				v[i]=1;
				dfs(x+1,s+1);
				v[i]=0;
			}
			else
			{
				v[i]=1;
				dfs(x+1,s);
				v[i]=0;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=(s[i-1]=='0');
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
