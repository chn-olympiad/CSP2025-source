#include<bits/stdc++.h>
using namespace std;
int n,k,ds[100005],dp[100005],a[100005],ma;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int o=a[i];
			for(int f=i+1;f<=j;f++)o^=a[f];
			if((o==k&&i!=j)||(i==j&&a[j]==k)){//cout<<a[i]<<' '<<a[j]<<' '<<(a[i]^a[j])<<endl;
				if(dp[i]==0)dp[j]=max(dp[j],dp[i]+1); 
				for(int m=0;m<i;m++)if(dp[m]!=0)dp[j]=max(dp[j],dp[m]+1);
				ma=max(ma,dp[j]);
			}
		}cout<<ma;
	return 0;
}
