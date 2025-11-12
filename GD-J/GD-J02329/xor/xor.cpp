#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,k,a[1000005],sm[1000005],la[1000005],l[1000005],dp[1000005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	la[0]=1;
	int s=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sm[i]=(sm[i-1]^a[i]);
		l[i]=la[sm[i]^k];
		la[sm[i]]=i+1;
//		cout<<l[i]<<" ";
		s+=a[i];
	}
	for (int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if (l[i]){
			dp[i]=max(dp[i],dp[l[i]-1]+1);
		}	
//		if (l[i]==i){
//			cout<<i<<" "<<a[i]<<" "<<dp[i]<<endl;
//		}
	}
	cout<<dp[n];
	return 0;
}
