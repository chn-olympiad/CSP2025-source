#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL n,k,ans,a[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=dp[i-1]^a[i];
	}
	LL l=1,r=1;
	while(r<=n){
		int x=dp[r]^dp[l-1];
		if(x==k){
			ans++;
			l=r+1;
			r=l;
		}
		else r++;
	}
	cout<<ans;
	return 0;
}
