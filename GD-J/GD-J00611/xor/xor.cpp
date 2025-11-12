#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1,0); //
	vector<int> sm(1025,-1); //存此时距离下标j最近的k的下标i 
	vector<int> dp(n+1,0); //到i为止最多数量为多少（即ans） 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	sm[0]=0;
	for(int i=1;i<=n;i++){
		if(sm[a[i]^k]!=-1){
			dp[i]=dp[sm[a[i]^k]]+1;
		} 
		dp[i]=max(dp[i-1],dp[i]);
		sm[a[i]]=i;
	} 
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
