#include<bits/stdc++.h>
#define N 500005
#define LL long long
//#define int long long
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;

int n,a[N],k,s[N],ma[1050000],dp[N],ans;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		int tmp=s[i]^k;
		dp[i]=dp[i-1];
		if(ma[tmp]) dp[i]=max(dp[i],dp[ma[tmp]]+1);
		ma[s[i]]=i;
		ans=max(ans,dp[i]);
	}
//	for(int i=1;i<=n;i++){
//		cout<<dp[i]<<" ";
//	}
//	puts("");
	cout<<ans;
//	printf("\ntime:%.0lfms",(double)clock());
	return 0;
}//知颖你太美