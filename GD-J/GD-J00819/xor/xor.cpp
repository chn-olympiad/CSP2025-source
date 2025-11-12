#include <bits/stdc++.h>
using namespace std;
/*
I LOVE CCF
*/
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,k;cin>>n>>k;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	vector<long long>pre(n+1);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]^a[i-1];
	}
	vector<long long>dp(n+1,0);
	unordered_map<long long,long long>last;
	last[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		auto it=last.find(pre[i]^k);
		if(it!=last.end()){
			dp[i]=max(dp[i],it->second+1);
		}
		it=last.find(pre[i]);
		if(it!=last.end()){
			it->second=max(it->second,dp[i]);
		}else{
			last[pre[i]]=dp[i];
		}
	}
	cout<<dp[n];
    return 0;
}
//#Shang4Shan3Ruo6Shui4
