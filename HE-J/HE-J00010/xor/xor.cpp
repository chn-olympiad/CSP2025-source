#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans,cnt;
bool f[N],A,B;
void dfs(int x,int s)
{
	f[x]=1;
	int t=a[x];
	if(t==k) dfs(x+1,s+1);
	for(int i=x+1;i<=n;i++)
	{
		t^=a[i];
		if(t==k) dfs(i+1,s+1);
	}
	ans=max(ans,s);
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(!A&&a[i]!=1) A=1;
		if(!B&&a[i]>1) B=1;
	}
	if(!A)
	{
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i]) dfs(i,0);
	}
	cout<<ans<<'\n';
	return 0;
}
