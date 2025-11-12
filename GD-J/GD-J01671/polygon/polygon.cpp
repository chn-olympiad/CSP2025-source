#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,a[5100],dp[5100],pre[5100];
int c(int a,int b){
	int y=1;
	for(int i=b;i>=b-a+1;i--){
		y*=i;
		y/=a-(b-i);
		y%=MOD;
	}
	return y;
}
int c2(int a){
	int u;
	for(int i=1;i<=a;i++){
		u+=c(i,a);
		u%=MOD;
	}
	return u;
}
void solve(int i,int yx){
	if(yx==0) return;
	if(yx==1){
		int j;
		for(j=1;j<=i-1;j++){
			if(a[j+1]!=1){
				break;
			}
		}
		dp[i]+=j;
		return;
	}
	dp[i]=dp[i-1]+1;
	int j;
	for(j=1;j<=i-1;j++){
		if(pre[j]>yx){
			break;
		}
	}
	dp[i]+=c2(j);
	dp[i]%=MOD;
	int k=j;
	for(k=j;k<=i-1;k++){
		if(a[k+1]>=yx){
			break;
		}
	}
	dp[i]+=k-j;
	dp[i]%=MOD;
	for(int l=j+1;l<=k;l++){
		solve(i,yx-a[l]);
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	sort(a,a+n+1);
	dp[1]=0;
	dp[2]=0;
	if(a[3]<pre[2]) dp[3]=1;
	else dp[3]=0;
	for(int i=4;i<=n;i++){
		dp[i]=dp[i-1];
		if(pre[i-1]>a[i]){
			solve(i,a[i]-pre[i-1]-1);
		}
	}
	cout<<dp[n];
	return 0;
}
