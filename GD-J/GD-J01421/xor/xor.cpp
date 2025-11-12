#include<bits/stdc++.h>
using namespace std;

int eh(int q,int w){
	int z=0,x=0,c[30]={0},v[30]={0},ret=0;
	while(q){
		c[++z]=q%2;
		q/=2;
	}
	while(w){
		v[++x]=w%2;
		w/=2;
	}
	for(int i=1;i<=max(z,x);i++){
		if(c[i]!=v[i]) ret+=(int)(1<<(i-1));
	}
	return ret;
}
int n,m,zzy,ans,a[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int p=0;
		int sum=a[i];
		if(a[i]==m){
			dp[i]=dp[i-1]+1;
			continue;
		}
		for(int j=i-1;j>=1;j--){
			sum=eh(sum,a[j]);
			if(sum==m){
				dp[i]=max(dp[i],dp[j-1]+1);
				p=1;		
			}
			
		}
		if(p==0) dp[i]=dp[i-1];
	}
	cout<<dp[n];
	return 0;
}
