/*
./compile xor a
./xor
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))
#define allof(o) (o).begin(),(o).end()
using namespace std;
int s[500005];
int f[500005];
int a[500005];
int n,m,ans;
void dfs(int x,int cnt)
{
// cerr<<x<<" "<<cnt<<'\n';
	if(f[x]>=cnt)return;
	f[x]=cnt;
	ans=max(ans,cnt);
	for(int i=x;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((s[j]^s[i-1])==m)
				dfs(j+1,cnt+1);
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i];
	if(*min_element(a+1,a+n+1)==1&&*max_element(a+1,a+n+1)==1&&!m) // 10 pts
		return cout<<n/2,0;
	if(*max_element(a+1,a+n+1)<=1) // 20 pts
	{
		if(m==1)
		{
			cout<<count(a+1,a+n+1,1);
			return 0;
		}
		int res=count(a+1,a+n+1,0);
		for(int i=1;i<n;i++)
			if(a[i]==1&&a[i+1]==1)
				res++,i++;
		cout<<res;
		return 0;
	}
	memset(f,-1,sizeof(f));
	dfs(1,0);
	cout<<ans;
	return 0;
}