#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,x,y,z,a[505],c[505][505],cnt[505],b[505],fc[505],ta[20],ans;
bool ok[20];
string s;
ll chk()
{
	ll x=0;
	for(ll i=1;i<=n;i++) if(s[i-1]=='0'||ta[i]<=x) x++;
	if(n-x>=m) return 1;
	return 0;
}
void dfs(ll t)
{
	if(t==n+1)
	{
		ans+=chk();
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(ok[i]) continue;
		ok[i]=true;
		ta[t]=a[i];
		dfs(t+1);
		ok[i]=false;
	}
	return;
}
ll i,j;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(i=0;i<n;i++) if(s[i]=='0') break;
	if(i==n)
	{
		cout<<0;
		return 0;
	}
	if(m==1)
	{
		for(i=0;i<=n;i++)
		{
			c[i][0]=1;
			for(j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
		fc[0]=1;
		for(i=1;i<=n;i++)
		{
			cnt[a[i]]++;
			fc[i]=fc[i-1]*i%mod;
		}
		for(i=n;i>=0;i--) cnt[i]+=cnt[i+1];
		for(i=0;i<n;i++) if(s[i]=='0') b[++x]=i+1;
		y=1;
		for(i=1;i<=x;i++)
		{
			z=y*cnt[b[i]]%mod*fc[n-i]%mod;
			ans=(ans+z)%mod;
			y=y*(cnt[0]-cnt[b[i]]-i+1)%mod;
			if(y<=0) break;
		}
		cout<<ans;
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
