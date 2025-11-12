#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],last[500005],book[5000005];
int dp[500005],Max[500005];
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=1;i<=5000000;i++) book[i]=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		last[i]=book[sum[i]^k];
		book[sum[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(last[i]!=-1){
			dp[i]=Max[last[i]]+1;
		}
		Max[i]=max(Max[i-1],dp[i]);
	}
	cout<<Max[n];
	return 0;
}