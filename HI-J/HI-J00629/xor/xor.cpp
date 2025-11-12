#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005];
int p[500005];
int xr[2000005];
int k=0;
int dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1];
	}
	for(int i=1;i<(1<<20);i++){
		p[i]=-1;
	}
	for(int i=1;i<=n;i++){
		p[a[i]]=i;
		int x=a[i]^k;
		if(p[x]>=0){
			xr[i]=p[x];
		}
		else{
			xr[i]=-1;
		}
	}
	int maxl=0;
	for(int i=1;i<=n;i++){
		if(xr[i]==-1){
			dp[i]=maxl;
		}
		else{
			dp[i]=max(dp[xr[i]]+1,maxl);
		}
		maxl=max(dp[i],maxl);
	}
	cout<<dp[n];
	return 0;
}
