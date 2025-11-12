#include<bits/stdc++.h>
using namespace std;
int cnt[1<<20];
int a[500006];
int dp[500006];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int res=0;
	for(int i=0;i<1048576;i++)cnt[i]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]^=a[i-1];
	cnt[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(0,cnt[a[i]^k]+1);
		dp[i]=max(dp[i-1],dp[i]);
		cnt[a[i]]=max(cnt[a[i]],dp[i]);
		res=max(res,dp[i]);
	}
	cout<<res<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
