#include<bits/stdc++.h>
using namespace std;
long long a[500005],x[500005],l[500005],r[500005],p,dp[500005][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(x[i]==k){
			l[++p]=i;
			r[p]=i;
		}
		for(int j=i+1;j<=n;j++){
			long long s=x[i]^x[j];
			if(s==k){
				l[++p]=i+1;
				r[p]=j;
				break;
			}
		}
	}
	dp[1][1]=1;
	for(int i=1;i<=p;i++){
		dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
		for(int j=i-1;j>=1;j--){
			if(l[i]>r[j]){
				dp[i][1]=dp[j][1]+1;
			}
		}
	}
	cout<<max(dp[p][0],dp[p][1]);
	return 0;
}
