#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define mod 998244353
int a[5005];
bool v[5005];
int ans,n;
bool m[2000005];
void dfs(int bs,int f,int sum,int maxl)
{
	if(bs>n) return;
	if(m[f]==1) return;
	m[f]=1;
	if(bs>=3)
	{
		if(sum>2*maxl)
			ans=(ans+1)%mod;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			f^=1<<i;
			dfs(bs+1,f,sum+a[i],max(maxl,a[i]));
			f^=1<<i;
			v[i]=0;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
