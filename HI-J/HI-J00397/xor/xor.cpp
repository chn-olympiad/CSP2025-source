#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],bj[20000005],dp[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int c=1;c<=n;c++) cin>>a[c]; 
	b[1]=a[1];
	for(int c=2;c<=n;c++) b[c]=a[c]^b[c-1];
	for(int c=1;c<=n;c++){
		dp[c]=dp[c-1];
		if(bj[(m^b[c])]!=0) {
		   dp[c]=max(dp[c],dp[bj[m^b[c]]]+1);
		}
		else if((m^b[c])==0) {
		   dp[c]=max(dp[c],1);	
		}
		bj[b[c]]=c;
	}
	cout<<dp[n];
	return 0;
} 
