#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e2+5,p=998244353;
int n,a[MAXN],dp[MAXN][MAXN][MAXN],comb[MAXN][MAXN],ma,ans;
int C(int n,int m){
	if(m==0||n==m)return 1;
	return (comb[n-1][m-1]+comb[n-1][m])%p;
}
bool cmp(int x,int y){
	return x<y;
}
bool check(){
	for(int i=1;i<=n;i++)if(a[i]!=1)return 0;
	return 1;
}
void solve(){
	int res=0;
	for(int i=3;i<=n;i++)res=(res+C(n,i))%p;
	cout<<res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<=n;i++)for(int j=0;j<=i;j++)comb[i][j]=C(i,j);
	if(check()){
		solve();
		return 0;
	}
	for(int k=0;k<=ma*2;k++){
		for(int j=1;j<=n;j++){
			for(int i=j;i<=n;i++){
				if(i-1>=j)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%p;
				if(k-a[i]>=0)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k-a[i]])%p;
				else dp[i][j][k]=(dp[i][j][k]+C(i-1,j-1))%p;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int k=0;k<=ma*2;k++)cout<<dp[i][j][k]<<" ";
//			cout<<"\n";
//		}
//		cout<<"\n\n";
//	}
	for(int i=3;i<=n;i++)for(int j=i;j<=n;j++)ans=(ans+dp[j-1][i-1][a[j]])%p;
	cout<<ans;
	return 0;
}
