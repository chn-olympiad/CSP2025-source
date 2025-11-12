#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,MOD=998244353;
long long n,ans;
long long a[N],dp[N][N];
bool flag=1,vis[N];
long long C(int n,int d){
	long long cnt1=1,cnt2=1;
	for(int i=n;i>=n-d+1;i--)cnt1=cnt1*i%MOD;
	for(int i=2;i<=d;i++)cnt2=cnt2*i%MOD;
	return cnt1/cnt2;
}
void dfs(int m,long long sum,int pos){
	if(m<1){
		if(sum>2*a[pos])ans=(ans+1)%MOD;
		return;
	}
	for(int i=pos+1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(m-1,sum+a[i],i);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(flag&&a[i]!=1)flag=0;
	}
	sort(a+1,a+1+n);
	if(n<=3){
		long long sum=a[1]+a[2]+a[3];
		if(sum>=2*a[3])cout<<1;
		else cout<<0;
	}
	else if(flag){
		for(int i=3;i<=n;i++)
			ans=(ans+C(n,i))%MOD;
		cout<<ans%MOD;
	}
	else{
		for(int i=3;i<=n;i++)dfs(i,0,0);
		cout<<ans%MOD;
//		for(int i=3;i<=n;i++){
//			for(int j=2;j<=i-1;j++)
//				ans=(ans+C(i-1,j))%MOD;
//			for(int j=0;j<=M;j++){
//				if(j<=a[i])ans=(ans+MOD-dp[i-1]][j])%MOD;
//				dp[i][j]=dp[i-1][j];
//				if(>0)
//			}
//		}
	}
	return 0;
}
