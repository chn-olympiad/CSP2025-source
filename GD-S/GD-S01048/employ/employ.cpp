#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505,MOD=998244353;
ll a[N],res,n,m,tmp[N];
bool vis[N];
string s;
void dfs(ll step)
{
	if(step>n)
	{
		ll cnt=0,cur=0;
		for(ll i=1;i<=n;i++)
		{
			if(s[i]=='1'&&tmp[i]>cnt)
				cur++;
			else
				cnt++;
		}
		if(cur>=m)
		{
			res++;
			res%=MOD;
		}
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			tmp[step]=a[i];
			vis[i]=1;
			dfs(step+1);
			vis[i]=0;
			tmp[step]=0;
		}
	 } 
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	s=" "+s;
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1);
	printf("%lld",res);
	return 0;
}
/*
I need CSP-S 1=!!!
*/
