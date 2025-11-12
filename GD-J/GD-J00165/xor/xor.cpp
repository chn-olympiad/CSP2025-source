#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],s[500005],mp[(1<<21)+10];
int lst[500005];
signed main(){
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	//freopen("or.in","r",stdin),发热open（“下哦人”，“我”，身体都挺） 
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>a[i],s[i]=(s[i-1]^a[i]);
	memset(lst,-1,sizeof lst);
	memset(mp,-1,sizeof mp);
	mp[0]=0;
	for (int i=1;i<=n;i++){
		int x=s[i]^k;
		if (mp[x]!=-1)lst[i]=mp[x]+1;
		mp[s[i]]=i;
	}
	for (int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if (lst[i]!=-1)dp[i]=max(dp[i],dp[lst[i]-1]+1);
	}
	cout<<dp[n];
	return 0;
}
