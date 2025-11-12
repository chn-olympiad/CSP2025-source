#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],mx[500005],dp[500005];
map<int,int> ma;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(ma[a[i]^k]!=0||a[i]==k) dp[i]=max(mx[ma[a[i]^k]]+1,dp[i]);
		mx[i]=max(dp[i],mx[i-1]);
		if(mx[ma[a[i]]]<mx[i]||ma[a[i]]==0){
			ma[a[i]]=i;
		}
	}
	printf("%lld\n",mx[n]);
	return 0;
}
