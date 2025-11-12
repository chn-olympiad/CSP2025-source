#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int mod=998244353;
int dp[N][N];//到第i个节点为止，前i-1个数任选k个可以超过a[i]的方案数
int n,a[N],qz[N];
bool cmp(int a,int b) {
	return a<b;
}
void dfs(int id,int k2) {
	if(k2==2)dp[id][k2]+=dp[id-1][id-2];
	else dp[id][k2]+=dp[id][k2-1];
	dp[id][k2]%=mod;
	if(id==n&&k2==n-1) {
		for(int i=1; i+2<=n-1; i++) {
			for(int j=1; j+n-1-1<=n-1; j++) {
				int pd=0;
				for(int k1=j+1; k1<=j+n-1-1; k1++) {
					pd+=a[k1];
				}
				//cout<<pd<<' '<<a[id]<<'\n';
				if(pd+a[j]>a[n]) {
					dp[n][n-1]++;
					//cout<<"XX"<<' '<<pd<<' '<<j<<' '<<a[j]<<' '<<id<<' '<<k2<<'\n';
				}
			}
		}
		cout<<dp[n][n-1]<<'\n';
		exit(0);
	}
	for(int i=1; i+2<=id-1; i++) {
		for(int j=1; j+k2-1<=id-1; j++) {
			int pd=0;
			for(int k1=j+1; k1<=j+k2-1; k1++) {
				pd+=a[k1];
			}
			//	cout<<pd<<' '<<a[id]<<'\n';
			if(pd+a[j]>a[id]) {
				dp[id][k2]++;
				//	cout<<"XX"<<' '<<pd<<' '<<j<<' '<<a[j]<<' '<<id<<' '<<k2<<'\n';
			}
		}
	}
	//cout<<88;
	if(k2+1<=id-1)dfs(id,k2+1);
	else dfs(id+1,2);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.ans","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>n;
	bool ff=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1)ff=1;
	}
	if(ff==0) {
		long long ans=1,num=0;
		for(int i=3; i<n; i++) {
			for(int j=n; j>i; j--) {
				ans=(ans*j)%mod;
			}
			for(int k=n-i; k>=1; k--) {
				ans/=k;
			}
			num=(num+ans)%mod;
		}
		cout<<num+1<<'\n';
		return 0;
	}
	if(n<=3) {
		if(n<=2) {
			cout<<0<<'\n';
			return 0;
		} else {
			if(a[1]+a[2]>a[3])cout<<1<<'\n';
			else cout<<0<<'\n';
			return 0;
		}
	}
	sort(a+1,a+n+1,cmp);
//	if(a[1]+a[2]>a[3])dp[3][2]=1;
//	for(int i=4;i<=n;i++){
//		for(int j=2;j<=i-1;j++){
//			int num=0;
//			for(int k=1;k<=n;k++){
//				if()
//			}
//		}
//	}
	dfs(3,2);
	return 0;
}

