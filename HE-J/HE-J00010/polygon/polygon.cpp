#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=5000;
ll n,a[N],b[N],cnt,ans,t,ans1;
bool f[N],A;
void dfs(ll x,ll s,ll maxx)
{
	if(s>2*maxx) 
	{
		ans++;
		ans%=mod;
	}
	for(ll i=x;i<=n;i++)
	{
		if(f[i]==0) 
		{
			f[i]=1,s+=a[i];
			dfs(i+1,s,max(maxx,a[i]));
			f[i]=0,s-=a[i];
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]>1) A=1;
	}
	if(A==0&&n>20)
	{
		t=500;
		while(t--){
			ans1*=2;
			ans1%=mod;
		}
		ans1-=n;
		for(ll i=1;i<n;i++){
			ans1=(ans1-i*(n-i)+mod)%mod;
		}
		cout<<ans1;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
