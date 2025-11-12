#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],f[5005],sum[5005];
long long ans;
struct node{
	int maxx,sum;
} dp[2][5005];
void dfs(int sum,int len,int maxx,int x){
	if(len>n){
		return;
	}
	if(len>=3&&sum>2*maxx){
		ans++;
	}
	for(int i=x+1;i<=n;++i){
		if(f[i]==0){
			f[i]=1;
			dfs(sum+a[i],len+1,max(maxx,a[i]),i);
			f[i]=0;
		}
	}
}
int lg[5006];
struct ST{
	int dp[100000][18];
	void build(){
		for(int i=1;i<=n;++i){
			dp[i][0]=a[i];
		}
		for(int j=1;j<=15;++j){
			for(int i=1;i<=n;++i){
				dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int check(int l,int r){
		int x=lg[r-l+1];
		return max(dp[l][x],dp[r-(1<<x)][x]);
	}
} st;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];//sum[i]+=sum[i-1];
	}
	dfs(0,0,0,0);
	cout<<ans%mod;
//	for(int i=1;i<=n;++i){
//		lg[i]=lg[i/2]+1;
//	}st.build();
//	for(int len=3;len<=n;++len){
//		for(int i=1,j=len;j<=n;i++,++j){
//			cout<<st.check(i,j)*2<<endl;
//			if(sum[j]-sum[i-1]>st.check(i,j)*2){
//				ans++;
//			}
//		}
//	}cout<<ans;
	return 0;
}
