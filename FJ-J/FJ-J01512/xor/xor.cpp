#include<cstdio>
#include<iostream>
using namespace std;
const int N=5e5+5;
int a[N];
int dp[N][2];
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int x=a[i],j=i-1;
		dp[i][0]=dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
		while(j>=1&&x!=k)x^=a[j--];
		if(x==k)dp[i][1]=max(max(dp[j][0],dp[j][1])+1,dp[i][1]);
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}
