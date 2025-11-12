#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,t=5e5;
long long a[maxn],n,k,dp[maxn],v,p,ans;
map<long long,long long>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		mp[a[i]]=i;
		dp[i]=dp[i-1];
		v=a[i]^k;
		if(a[i]==k){
			dp[i]=dp[i-1]+1;
			continue;
		}
		if(mp[v]<i&&mp[v]!=0){
			dp[i]=max(dp[i],dp[mp[v]-1]+1);
		}
	}
	cout<<dp[n];
    return 0;
}
