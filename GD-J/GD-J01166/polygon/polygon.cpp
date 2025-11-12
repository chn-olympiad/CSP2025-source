#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5005,MOD=998244353;
ll n,a[N],ans;
void dfs(ll step,ll sum,ll maxx)
{
	if(step>n)
	{
		if(sum>maxx*2)
		{
			ans++;
			ans%=MOD;
		}
		return;
	}
	dfs(step+1,sum+a[step],max(maxx,a[step]));
	dfs(step+1,sum,maxx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
/*
My Luogu uid is 1384934.
My Luogu user name is ZTengW.
Of course,I don't now how to spell guanzhu in English.
So please guanzhu me!

focacode.com is an online judge website.
You can get many interesting problems on it.
And welcome to join FOCA Oj!
Tips:FOCA means Focus On Coding and Applications.
*/
