#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6+10;
int dp[N],s[N],t[M],n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=2e6;i++) t[i]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			//可以直接加
			dp[i] =dp[i-1]+1;
			t[s[i]]=i;
			continue;
		}
		int wtn=t[(k^s[i])];
		if(wtn!=-1){
			dp[i]=dp[wtn]+1;
		}
		t[s[i]]=i;
		dp[i]=max(dp[i-1],dp[i]);
	}
//	for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
//	cout<<"\n";
	cout<<dp[n];
	return 0;
}
