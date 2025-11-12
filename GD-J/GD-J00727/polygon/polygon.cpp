#include<bits/stdc++.h>
using namespace std;
int n,a[5145];
long long dp[5145],cnti;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	dp[0]=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=5001;j>a[i];j--){
			cnti+=dp[j];
			cnti%=998244353;
			dp[min(5001,j+a[i])]+=dp[j];
			dp[min(5001,j+a[i])]%=998244353;
		}for(int j=a[i];j>=0;j--){
			dp[min(5001,j+a[i])]+=dp[j];
			dp[min(5001,j+a[i])]%=998244353;
		}
	}cout<<cnti;
	return 0;
} 
