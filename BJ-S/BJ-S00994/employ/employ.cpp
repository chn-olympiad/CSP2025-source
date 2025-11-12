#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
#define mod 998244353
ll n,m,c[502],a[502],ans;
basic_string<char>s;
bool used[502];
void chk()
{
	ll cnt=0;
	for (ll i=1;i<=n;i++)
	{
		if (cnt>=c[a[i]]||s[i]=='0')
		{
			cnt++;
		}
	}
	if (n-cnt>=m)ans++;
	if (ans>mod)ans%=mod;
}
void dfs(ll x)
{
	if (x>n)
	{
		return chk();
	}
	for (ll i=1;i<=n;i++)
	{
		if (used[i])continue;
		a[x]=i;
		used[i]=1;
		dfs(x+1);
		used[i]=0;
	}
}
int main()
{
	faster;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for (ll i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}//8
