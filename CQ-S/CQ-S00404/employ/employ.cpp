#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=505;
int fct[N];
int n,m;
string s;
int c[N];
//int dp[N][N][N];
void solve1(){
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0<<'\n';
				return;
			}
		}
		cout<<fct[n]<<'\n';
		return;
	}
	cout<<0<<'\n';
	return;
//	dp[0][0][0]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<i;j++){//insert position 
//			for(int k=0;k<=j;k++){//haved delete
//				if(k>=c[i]){
//					dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%mod;
//					int res=dp[i-1][j][k];
//					dp[i][j+1][k+1]=(dp[i][j+1][k+1]+res)%mod;
//					for(int p=j+2;p<=i;p++){
//						res=res*(i-p+1)%mod;
//						dp[i][p][k+(p-j)]=(dp[i][p][k+(p-j)]+res)%mod;
//					}
//				}
//				else{
//					dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%mod;
//					dp[i][j+1][k]=(dp[i][j+1][k]+dp[i-1][j][k])%mod;
////					for(int p=j+1;p<=i;p++){
////						dp[i][p][k]=(dp[i][p][k]+dp[i-1][p-1][k])%mod;
////					}
//				}
//			}
//		} 
//	}
////	for(int i=1;i<=n;i++){
////		for(int j=0;j<=i;j++){
////			for(int k=0;k<=j;k++){
////				cout<<c[i]<<':'<<i<<' '<<j<<' '<<k<<':'<<dp[i][j][k]<<'\n';
////			}
////		}
////	}
//	int ans=0;
//	for(int i=0;i<=n;i++){
//		if(n-i>=m){
//			ans=(ans+dp[n][n][i])%mod;
//		}
//	}
//	cout<<ans<<'\n';
}
int d[N],cnt;
void solve2(){
	int ans=fct[n];
	int res=1;
	int zero=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			int tot=0;
			for(int j=1;j<=n;j++){
				if(c[j]<=i-1){
					tot++;
				}
			}
			res=res*(tot-cnt)%mod;
			cnt++;
		}
		else{
			zero++;
		}
	}
	res=res*fct[zero]%mod;
	ans=(ans-res+mod)%mod;
	cout<<ans<<'\n';
}
int f[20][(1<<18)+5];
void solve3(){
	f[0][0]=1;
	for(int p=0;p<(1<<n);p++){
		int tot=0;
		for(int i=1;i<=n;i++){
			if((p>>i-1)&1){
				tot++;	
			}
		}
		for(int i=1;i<=n;i++){
			if((p>>i-1)&1){
				continue;	
			}
			for(int j=0;j<=tot;j++){
				if(s[tot+1]=='0'||j>=c[i]){
					f[j+1][p|(1<<i-1)]=(f[j+1][p|(1<<i-1)]+f[j][p])%mod;
				}
				else{
					f[j][p|(1<<i-1)]=(f[j][p|(1<<i-1)]+f[j][p])%mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++){
//		cout<<f[i][(1<<n)-1]<<'\n';
		if(n-i>=m){
			ans=(ans+f[i][(1<<n)-1])%mod;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	fct[0]=1;
	for(int i=1;i<=n;i++){
		fct[i]=fct[i-1]*i%mod;
	}
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	int A_TOT=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			A_TOT++;
		}
	}	
	if(n<=18){//20
		solve3();
		return 0;	
	}	
	if(m==1){//12
		solve2();
		return 0;
	}
	if(A_TOT==n){
		solve1();
		return 0;
	}
	if(m==n){//4
		cout<<0<<'\n';
		return 0;
	}
	cout<<0<<'\n';
	return 0;
}
