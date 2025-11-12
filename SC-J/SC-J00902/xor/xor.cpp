#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
ll n,k,a[500005],pre[500005],need[500005],dp[500005];
map<ll,ll> m;
ll g[500005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1] ^ a[i];
	}
	for(int i=1;i<=n;i++){
		need[i]=pre[i-1] ^ k;
	}
	for(int i=1;i<=n;i++){
		if(m[pre[i]]){
			g[i]=m[pre[i]];
			m[pre[i]]=0;
		}
		m[need[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k)g[i]=i;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(g[i])dp[i]=max(dp[i],dp[g[i]-1]+1);
	}
	cout<<dp[n];
}
