#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],num[1005][1005],dp[1005][1005],maxx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(i==j)num[i][j]=a[i];
			else num[i][j]=num[i][j-1]^a[j];
	for(int e=0;e<n;e++){
		for(int l=1;l+e<=n;l++)
			for(int r=l+e;r<=n;r++){
			dp[l][r]=dp[1][l-1];
			if(num[l][r]==k)dp[l][r]++;maxx=max(maxx,dp[l][r]);}
	}
	printf("%d",maxx);
	return 0;
}
