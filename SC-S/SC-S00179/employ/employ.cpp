#include<bits/stdc++.h>
using namespace std;
const int N=505,M=998244353;
long long n,vis[N],m,a[N],sum[N][N],x[N];
long long dfs(int cen,int js,int jj)
{
//	cout<<cen<<' '<<js<<' '<<jj<<'\n';
//	for(int i=1;i<=n;i++)
//		cout<<vis[i]<<' ';
//	cout<<'\n';
	if(cen>n&&js>=m)return 1;
	if(sum[cen][jj]+js<m)return 0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		ans+=dfs(cen+1,js+(x[cen]&(a[i]>jj)),jj+(!(x[cen]&(a[i]>jj))));
		vis[i]=0;
		ans%=M;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;cin>>c;x[i]=c-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
		for(int j=n;j>=0;j--)
		{
			if(a[i]<j)sum[i][j]=sum[i+1][j+1];
			else if(x[i]==0)sum[i][j]=sum[i+1][j+1];
			else sum[i][j]=sum[i+1][j]+1;
		}
	cout<<dfs(1,0,0);
}