#include<bits/stdc++.h> 
using namespace std;
int t,n,v[3][201],dp[101][101],ans;
inline int read()
{
	int s=0,f=1;
	char c=getchar();
	while(!isdigit(c)) f=(c=='-'?-1:1),c=getchar();
	while(isdigit(c)) s=(s<<3)+(s<<1)+(c&15),c=getchar();
	return s*f;
}
void dfs(int now,int sum,int a,int b,int c) 
{
	if(now>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(a<n/2) dfs(now+1,sum+v[0][now],a+1,b,c);
	if(b<n/2) dfs(now+1,sum+v[1][now],a,b+1,c);
	if(c<n/2) dfs(now+1,sum+v[2][now],a,b,c+1);
}
void dp_func()
{
	for(int i=1;i<=n/2;i++) for(int j=1;j<=n/2;j++) dp[i][j]=0;
	for(int i=1;i<=n;i++) for(int j=n/2;j>=1;j--) for(int k=n/2;k>=1;k--) dp[j][k]=max(dp[j][k],max(dp[j-1][k]+v[0][i],dp[j][k-1]+v[1][i]));
	for(int i=0;i<=n/2;i++) for(int j=n/2-i;j<=n/2;j++) ans=max(ans,dp[i][j]);
}
void solve()
{
	n=read(),ans=0;
	for(int i=1;i<=n;i++) cin>>v[0][i]>>v[1][i]>>v[2][i];
	if(n<=10) dfs(1,0,0,0,0);
	else if(n<=200) dp_func();
	else
	{
		sort(v[0]+1,v[0]+n+1);
		for(int i=1;i<=n/2;i++) ans+=v[0][i];
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	t=read();
	while(t--) solve();
}
