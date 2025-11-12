#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
	freopen("r","xor.in",stdin);
	freopen("w","xor.out",stdout);
	int n,k;cin>>n>>k;
	
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int dp[100005];
	int ans=0;
	int dz=0;
	for(int i=1;i<=n;i++){
		if(arr[i]==k){
			ans++;
			for(int ko=0;ko<=dz;ko++){
				dp[ko]=0	;
			}
			dz=0;
		}else{
			dp[dz]=arr[i];
			dz++;
			if(dz!=1){
				for(int j=0;j<dz-1;j++){
					int gp=dp[j]^arr[i];
					cout<<gp<<endl;
					dp[j]=gp;
					if(gp==k){
					ans++;
					for(int kl=0;kl<=dz;kl++){
						dp[kl]=0;
						}
					dz=0;
					break;
					}
				}
			}
			
		}
	}
	cout<<ans<<endl;
}
