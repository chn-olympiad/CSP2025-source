#include<bits/stdc++.h>
using namespace std;

int a[500005];
int q[500005];//have not 0
int x[500005];//have 0
int b[500005];
int dp[500005];
int n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	memset(b,-1,(n+3)*sizeof(int));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=a[i]^q[i-1];
		x[i]=q[i]^k;
	}
	x[0]=0^k;
	for(int i=0;i<=n;i++){
		int j=i+1;
		for(;j<=n;j++){
			if(q[j]==x[i]){
				b[j]=j-i-1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){	
		dp[i]=dp[i-1];
		if(b[i]>=0)dp[i]=max(dp[i],dp[i-b[i]]+1);
	}	
	cout<<dp[n];
	
	return 0;
}