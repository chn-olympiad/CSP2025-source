#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<int>g[N];
int n,k;
int a[N],p[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int o=1;o<=i;o++){
			p[o]^=a[i];
			if(p[o]==k)g[i].push_back(o);
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int o:g[i]){
			dp[i]=max(dp[i],dp[o-1]+1);
		}
	}
	cout<<dp[n];
	return 0;
}