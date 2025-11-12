#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],dp[1005][1005],sum,ans=0;
long long wcnm(long long x,long long y,long long sb){
	if(x<=1&&y<=1){
		if(x==1||y==1){
			if(x!=y)return sb;
			else return 0;
		}else return 0;
	}
	if(x%2==1||y%2==1){
		if(x%2!=y%2)return sb+wcnm(x/2,y/2,sb*2);
		else return 0+wcnm(x/2,y/2,sb*2);
	}else return 0+wcnm(x/2,y/2,sb*2);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			for(long long j=1;j<=n;j++){
				dp[j][i]=1;
			}
		}
	}
	for(long long i=1;i<n;i++){
		long long t=i;
		for(long long j=2;j<=n;j++){
			if(dp[i][j]>0){
				dp[i][j]+=dp[i][j-1];
				continue;
			}
			sum=wcnm(t,t+1,1);
			for(long long z=t+2;z<=j;z++){
				if(dp[i][z]>0)break;
				sum=wcnm(sum,a[z],1);
			}
			if(sum==k)dp[i][j]++,t=j+1;
			dp[i][j]+=dp[i][j-1];
		}
	}
	for(long long i=1;i<=n;i++){
		ans=max(ans,dp[i][n]);
	}	
	cout<<ans<<endl;
	return 0;
}
