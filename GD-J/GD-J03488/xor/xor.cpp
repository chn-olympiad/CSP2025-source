#include<bits/stdc++.h>
using namespace std;

constexpr int N=5e5+5;
int n,k;
int a[N],sum[N],dp[N];
vector<int>v[(1<<20)+5];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	v[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		v[sum[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j:v[k^sum[i]]){
			if(j>=i) break;
			dp[i]=max(dp[i],dp[j]+1);
		}
	}
	cout<<dp[n];
}
