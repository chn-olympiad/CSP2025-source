#include<bits/stdc++.h>
using namespace std;
int n,k,a[500100],v[500100],dp[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],v[i]=-1;
	for(int r=n;r>0;r--)
		for(int sum=a[r],l=r;l>0;l--,sum^=a[l])
			if(sum==k){v[r]=l;break;}
	for(int r=1;r<=n;r++)
		if(v[r]==-1)dp[r]=dp[r-1];
		else dp[r]=max(dp[r-1],dp[v[r]-1]+1);
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
