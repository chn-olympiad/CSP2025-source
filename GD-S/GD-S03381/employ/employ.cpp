#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=502,p=998244353;
int n,m,c[N],ans,dp[N][N];
bool b[N],vis[N];
char ch;
void dfs(int i,int C){
	if(n-C<m)return;
	if(i==n+1)++ans;
	else if(!b[i])dfs(i+1,C+1);
	else for(int j=1;j<=n;j++)if(!vis[j])vis[j]=1,dfs(i+1,C+(C>=c[j])),vis[j]=0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;
	int b0=0;
	for(int i=1;i<=n;i++)cin>>ch,b[i]=ch=='1',b0+=!b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=18){
		dfs(1,0);
		for(int i=1;i<=b0;i++)ans=ans*i%p;
	}else if(m==n){
		for(int i=1;i<=n;i++)if(!b[i]||!c[i])cout<<0,exit(0);
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%p;
	}else{
		sort(c+1,c+1+n);
		dp[0][0]=1;
		for(int i=1;i<=n;i++)for(int j=0;j<i;j++){
			if(j>=c[i])dp[i][j+1]=(dp[i][j+1]+dp[i-1][j]*(j-c[i]+1))%p;
			dp[i][j]=(dp[i][j]+dp[i-1][j]*(i-max(0ll,j-c[i]+1)))%p;
		}
		for(int i=0;i<=n-m;i++)ans=(ans+dp[n][i])%p;
	}
	cout<<ans;
}
