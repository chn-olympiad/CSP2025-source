#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5005];
int dp[5005][5005];
int pre[5005];
	int n;
	int vis[5005];
	int cnt=0;
void  dfs(int s,int sl){
	if(s==sl){
		int tt=0;
		int ma=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1)tt+=a[i];
			if(a[i]>ma)ma=a[i];
		}
		if(tt>2*ma)cnt++;
		cnt%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		else{
			vis[i]=1;
			dfs(s+1,sl);
			vis[i]=0;
		}
	}
}
bool cp(int l,int r){
	return l>=r;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cp);
	if(n<=3){
		if(a[1]+a[2]+a[3]>2*a[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n<=25){
		for(int i=3;i<=n;i++){
			dfs(0,i);
		}
		cout<<cnt;
	}else{
//	for(int i=1;i<=n;i++){
//		pre[i]=pre[i-1]+a[i];
//	}
//	int sta=3;
//	while(1){
//		if(pre[sta]>a[1]){
//			break;
//		}else{
//			sta++;
//		}
//	}
//	dp[sta][sta]=1;
//	for(int i=sta;i<=n;i++){
//		for(int j=3;j<=i;j++){
//			dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
//		}
//	}
//	int ans=0;
//	for(int j=3;j<=n;j++){
//		ans+=dp[n][j];
//		ans%=mod;
//	}
//	cout<<ans;
	int ans=0;
	for(int j=3;j<=n;j++){
		int an=1;
	for(int i=j;i<=n;i++){
		an*=i;
		an%=mod;
	}
	ans+=an;
	}
	cout<<ans;
	}
	return 0;
} 
/*
5
1 2 3 4 5

*/
/*
4 3
2 1 0 3
*/
/*
4 0
2 1 0 3
*/
//63 69 12701
