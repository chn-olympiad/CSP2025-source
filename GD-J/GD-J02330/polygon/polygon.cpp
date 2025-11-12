#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005,mod=998244353;
int n;
int ans;
int sum,mx,mn=1e9+7;
int a[MAXN];
int dp[50005][505];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sum=mx=mn=a[1];
	dp[a[1]][a[1]]=dp[0][0]=1;
	for(int i=2;i<=n;i++){
		sum+=a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		for(int j=sum;j>=a[i];j--){
			for(int k=0;k<a[i];k++) dp[j][a[i]]=(dp[j][a[i]]+dp[j-a[i]][k])%mod;
			for(int k=a[i];k<=mx;k++) dp[j][k]=(dp[j][k]+dp[j-a[i]][k])%mod;
		}
	}
	for(int j=0;j<=sum;j++){
		for(int k=0;k<=mx&&(2*k)<j;k++){
			ans=(ans+dp[j][k])%mod;
		}
	}
	cout<<ans;
	return 0;
}



