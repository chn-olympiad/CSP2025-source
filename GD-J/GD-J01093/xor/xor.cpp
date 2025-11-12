#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],dp[500010],sum[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	} 
	cout<<n;
	return 0;
}
