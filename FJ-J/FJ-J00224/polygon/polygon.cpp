#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5010],ans,n;
bool v[5010];
ll read()
{
	ll a=0;char b=getchar();
	for(;b>'9'||b<'0';b=getchar());
	for(;b>='0'&&b<='9';a=a*10+b-48,b=getchar());
	return a;
}
void dfs(ll x,ll sum,ll mx)
{
	if(sum>mx*2) ans++;
	for(int i=x+1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			dfs(i,sum+a[i],max(mx,a[i]));
			v[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	dfs(0,0,0);	
	cout<<ans;
	return 0;
}