#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5;
ll n,k,a[N+10],sum,ans,v[N],Ans;
ll read()
{
	ll a=0;char b=getchar();
	for(;b>'9'||b<'0';b=getchar());
	for(;b>='0'&&b<='9';a=a*10+b-48,b=getchar());
	return a;
}
void dfs(ll x,ll sum)
{
	if(x>n) return;
	if(sum==k) 
	{
		ans++;
		dfs(x+1,a[x+1]);
		return;
	}
	dfs(x+1,sum^a[x+1]);
}
int main()
{
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=n;i>=1;i--)
	{
		ans=0;
		dfs(i,a[i]);
		Ans=max(ans,Ans);
	}
	cout<<Ans;
	return 0;
}