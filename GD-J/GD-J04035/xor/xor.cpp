#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,kk,a[500005],zx=INT_MAX,zd=INT_MIN,zdd; 
void dfs(ll k,ll x)
{
	ll b=0;
	for(int i=k;i<=n;i++)
	{
		if(n-i+1<zdd-x) break;
		b^=a[i];
		if(b==kk) dfs(i+1,x+1);
	}
	zdd=max(zdd,x);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> kk;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		zx=min(zx,a[i]),zd=max(zd,a[i]);
	}
	if(zx==1 && zd==1 && kk==0)
	{
		cout << n/2;
		return 0;
	}
	for(int i=1;i<=n-zdd;i++) dfs(i,0);
	cout << zdd;

	return 0;
}
/*
Rp++
T3 a little difficult?
(应该是DP吧......but不会怎么办qwq)
David_dai CCF终于发力了吗:) 
德-摩根定律了解一下?(虽然P用没有
*/
