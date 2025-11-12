#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5001],s[5001],pw2[5001]={1},ans;
void dfs(int now,int sum,int tar)
{
	if(sum>tar)
	{
		ans=(ans+pw2[now])%mod;
		return;
	}
	if(!now) return;
	dfs(now-1,sum+a[now],tar);
	if(s[now-1]+sum>tar) dfs(now-1,sum,tar);
}
int main()
{
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	for(int i=1;i<=5000;i++) pw2[i]=(pw2[i-1]*2)%mod;
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) dfs(i-1,0,a[i]);
	cout<<ans;
}
