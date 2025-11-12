#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=(1<<20)+5;
int n,k,a[N],s[N];
int dp[N][2],lst[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	memset(lst,-1,sizeof(lst));lst[0]=0;
	for (int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if (lst[s[i]^k]+1)
			dp[i][1]=dp[lst[s[i]^k]+1][0]+1;
		lst[s[i]]=i;
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}
