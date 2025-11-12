#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=998244353;
ll n,ans,ma;
ll a[5010],v[5010],b[5050];
void dfs(int t,ll s,ll ma,string s1)
{
	if(t>n)
	{
		if(s>2*ma) 
			ans=(ans+1)%N;
		return;
	}
	dfs(t+1,s+a[t],a[t],s1+" "+char(a[t]+48));
	dfs(t+1,s,ma,s1);
}
ll C(int x,int y)
{
	int s=1;
	for(int i=x;i>=x-y+1;i--)
		s=s*i%N;
	for(int i=2;i<=y;i++)
		s=s/i;
	return s%N;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(a[i],ma);
	}
//	ma=1;
	if(ma==1)
	{
		for(int i=3;i<=n;i++)
			ans+=C(n,i);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,"");
	cout<<ans%N;
	return 0;
 } 
