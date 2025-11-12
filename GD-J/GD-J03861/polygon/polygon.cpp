#include<iostream>
using namespace std;
typedef long long ll;
const ll M=998244353;
ll n,ans=0;
ll a[5010];
void dfs(ll s,ll ma,ll p)
{
	if(p==n+1)
	{
		if(s>ma*2)
			ans++;
		return;
	}
	dfs(s+a[p],max(ma,a[p]),p+1);
	dfs(s,ma,p+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,1);
	cout<<ans%M;
	return 0;
}
