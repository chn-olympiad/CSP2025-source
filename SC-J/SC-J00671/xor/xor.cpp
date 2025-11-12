#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int xr[2000005];
int las[2000005];
int frm[2000005];
int dp[2000005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	memset(las,-1,sizeof(las));
	memset(frm,-1,sizeof(frm));
	las[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xr[i]=xr[i-1]^a[i];
		if(las[xr[i]^k]!=-1){
			frm[i]=las[xr[i]^k];
		}
			las[xr[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(frm[i]==-1){
			dp[i]=dp[i-1];
		}
		else{
			dp[i]=max(dp[i-1],dp[frm[i]]+1);
		}
	}
	cout<<dp[n];
}