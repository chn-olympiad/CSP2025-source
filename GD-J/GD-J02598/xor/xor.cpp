#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,k,w;
ll a[N],b[N];
ll dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if(dp[j-1]+1<=dp[i])break;
			w=b[i]^b[j-1];
			if(w==k)dp[i]=max(dp[i],dp[j-1]+1);
			else dp[i]=max(dp[i],dp[j-1]);
		}
	}
	cout<<dp[n];
	return 0;
}
