#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
void dfs(int m,int cnt,int sum,int maxx)
{
	if(cnt>=3&&sum>maxx*2) 
	{
		++ans;
		if(ans==998244353)ans%=998244353;
	}
	for(int i=m+1;i<=n;++i)
	{
		dfs(i,cnt+1,sum+a[i],max(maxx,a[i]));
	}
}
int main()
{
	freopen("")
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	dfs(0,0,0,0);
	cout<<(int)(ans)<<'\n';
	return 0;
}
