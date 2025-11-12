#include<bits/stdc++.h>
using namespace std;
bool ispg(int s,int mx)
{
	if(s>mx*2) return 1;
	return 0;
}
const int mod=998244353;
int a[5003],n;
unsigned long long ans;
void dfs(int k,int io,int sum,int maxx)
{
	if(k>n) return;
	sum+=a[k]*io;
	maxx=max(maxx,a[k]*io);
	if(ispg(sum,maxx)*io)
	{
		ans++;
		ans%=mod;
	}
	k++;
	dfs(k,1,sum,maxx);
	dfs(k,0,sum,maxx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,1,0,0);
	dfs(1,0,0,0);
	cout<<ans%mod;
	return 0;
}
