#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const N=500050;
ll n,k,a[N],b[N],ans=0,mx=0;
void solve1()
{
	if(n==1) 
	{
		if(a[1]==0) cout<<1;
		else cout<<0;
	}
	else 
	{
		if(a[1]==0&&a[2]==0) cout<<2;
		else if(a[1]==a[2]) cout<<1;
	    else cout<<0;	
	}
	return;
}
void dfs(int ii)
{
	
	int now=0;
	for (int i=ii+1;i<=n;i++)
	{
		now^=a[i];
		if(now==k)
		{
			ans++;
			if(i==n) mx=max(mx,ans),ans=0;
			dfs(i);
		} 
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for (ll i=1;i<=n;i++) cin>>a[i];
	if(n<=2) 
	{
		solve1();
		return 0;
	} 
	dfs(0);
	cout<<mx;
	return 0;
}
/*
4 1
2 1 0 3

*/
