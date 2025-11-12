#include<bits/stdc++.h>
using namespace std;
const long long md=998244353;
int n,m,pre[505],c[505],dp[505][505][505],ans=0; 
char ch;
bool vis[505];
void dfs(int dep,int ls){
	if(dep>n){
		if(n-ls>=m){
		++ans;
		ans%=md;	
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i]=1;
		if(pre[dep]-pre[dep-1]==1||ls>=c[i])dfs(dep+1,ls+1);
		else dfs(dep+1,ls);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		cin>>ch;
		pre[i]=pre[i-1];
		if(ch=='0')++pre[i];
	}
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	if(n<=18){
		dfs(1,0);
		printf("%d",ans);
	}
	if(pre[n]==0){
		long long ans=1;
		for(long long i=1;i<=n;++i){
			ans*=i;
			ans%=md;
		}
		printf("%lld\n",ans);
	} 
//	dp[0][0][0]=1;
//	for(int i=1;i<=n;++i){
//		if(pre[i]-pre[i-1]==1){
//			for(int j=1;j<=n;++j)
//				for(int k=0;k<=n;++k)
//					dp[i][j][k]=dp[i-1][j-1][k];
//		}
//		for(int j=1;j<=n;++j){
//			if(pre[i-1]>=c[i])dp[i][j][k]=dp[]
//			for(int k=0;k<=n;++k){
//				
//			}
//		}
//	}
	return 0;
}
