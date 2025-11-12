#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[510010],dp[510010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k;
		a[i]=(a[i-1]^k);
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if((a[i]^a[j-1])==m){
				dp[i]=max(dp[i],dp[j-1]+1);
//				cout<<i<<" "<<j<<" "<<(a[i]^a[j-1])<<" "<<dp[i]<<endl;
				break;
			}
		}
	}
//	cout<<endl;
	cout<<dp[n];
	return 0;
}

