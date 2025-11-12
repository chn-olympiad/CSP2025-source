#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e3;
const int mod=998244353;
int n,ans,flag=1;
int a[N],b[N],vis[N],dp[N][N];
int C(int a,int b){
	int s=1;
	for(int i=0;i<b;i++){
		s*=(a-i);
	}
	for(int i=1;i<=b;i++){
		s/=i;
	} 
	s%=mod;
	return s;
}
void dfs(int cnt,int x){
	if(cnt>=3){
		int mmax=0,sum=0;
		for(int i=1;i<=cnt;i++){
			mmax=max(mmax,b[i]);
			sum+=b[i];
		}
		if(sum>2*mmax){
			ans++;
//			for(int i=1;i<=cnt;i++){
//				cout<<b[i]<<" ";
//			}
//			cout<<"\n";
			ans%=mod;
		}
	}
	for(int i=x+1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		b[++cnt]=a[i];
		dfs(cnt,i);
		cnt--;
		vis[i]=0;
	}
	return ;
}
signed main(){
//	freopen("polygon3.in","r",stdin);
//	freopen("polygon1.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag){
		for(int i=3;i<=n;i++){
			dp[i][i]=1;
		}
		for(int i=3;i<=n;i++){
			dp[i][3]=C(i,3);
//			cout<<dp[i][3]<<" ";
		}
		for(int i=5;i<=n;i++){
			for(int j=4;j<i;j++){
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
				dp[i][j]%=mod;
			} 
		}
//		for(int i=1;i<=n;i++){
//			cout<<dp[n][i]<<" ";
//		}
		for(int i=1;i<=n;i++){
			ans+=dp[n][i];
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	}
	dfs(0,0);
	printf("%lld",ans);
	return 0;
}
//^Òì»ò 

 

