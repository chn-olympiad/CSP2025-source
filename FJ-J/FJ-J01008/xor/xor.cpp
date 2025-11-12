#include<iostream>
#include<cstring>
using namespace std;

int dp[500010];
int pre[500010];
int f[2000010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(f,-1,sizeof f);
	int n,k;
	cin>>n>>k;
	int sum=0;
	f[0]=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		sum^=x;
		pre[i]=f[sum^k];
		f[sum]=i;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(pre[i]!=-1)dp[i]=max(dp[i],dp[pre[i]]+1);
//		cout<<dp[i]<<" "<<dp[pre[i]]<<" "<<pre[i]<<"\n";
	}
	cout<<dp[n];
}
