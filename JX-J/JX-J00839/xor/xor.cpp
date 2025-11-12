#include<bits/stdc++.h>
using namespace std;
int a[500005],dp[500005],idl=0,l;
void dfs(int n,bool f[]){
	if(n==0){
		return;
	}	
	if(n%2)f[idl]=!f[idl];
	n/=2;
	idl++;
	dfs(n,f);
	
}	
bool f[25],kp[25];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	memset(kp,0,sizeof(kp));
	dfs(k,kp);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		memset(f,0,sizeof(f));
		for(int j=i;j>=1;j--){
			idl=0;
			dfs(a[j],f);
			bool pl=true;
			for(int m=0;m<idl;m++){
				if(f[m]!=kp[m])pl=false;
				if(!pl)break;
			}	
			if(pl){
				dp[i]=max(dp[j-1]+1,dp[i]);
			}	
		}	
	}	
	cout<<dp[n];
	return 0;
}
