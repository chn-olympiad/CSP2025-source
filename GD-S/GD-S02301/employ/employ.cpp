#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+5,mod=998244353;
string s;
int n,m,a[maxn],ans[maxn][20],fac[maxn],dp[maxn];
int dfs(int num,int x){
//	cout<<x<<" "<<num<<" "<<ans[num][x]<<" {";
//	for(int i=1;i<=n;i++)if(num&(1<<i-1))cout<<i<<",";
//	cout<<"}\n";
	if(ans[num][x])return ans[num][x];
	int res=0,cnt=0;
	for(int i=1;i<=n;i++)if(num&(1<<i-1))cnt++;
//	cout<<"cnt:"<<cnt<<"\n";
	if(cnt-x>=m){
//		cout<<"num:"<<num<<"\n";
//		cout<<x<<" "<<num<<" "<<ans[num][x]<<" {";
//		for(int i=1;i<=n;i++)if(num&(1<<i-1))cout<<i<<",";
//		cout<<"}";
//		cout<<" "<<fac[n-cnt]<<"\n";
		return ans[num][x]=fac[n-cnt];
	}
	for(int i=1;i<=n;i++){
		if(!(num&(1<<i-1))){
			res=(res+dfs(num|(1<<i-1),x+(s[cnt+1]=='0'||a[i]<=x)))%mod;
		}
	}
////	if(res!=0){
////		cout<<x<<" "<<num<<" "<<ans[num][x]<<" {";
////		for(int i=1;i<=n;i++)if(num&(1<<i-1))cout<<i<<",";
////		cout<<"}";
////		cout<<" "<<res<<"\n";
////	}
	return ans[num][x]=res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;i++)cin>>a[i];
//	cout<<C(1,1)<<"\n";
//	for(int i=1;i<=n;i++)res+=ans[(1<<n)-1][i];
	cout<<dfs(0,0)<<"\n";
//	for(int i=0;i<=(1<<n)-1;i++)for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<ans[i][j]<<"\n";
	return 0;
}

