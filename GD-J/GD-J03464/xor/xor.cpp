#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s[500005],dp[500005],a[500005];
int n,k;
map<ll,ll>b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),s[i]=s[i-1]^a[i];
	for(int i=0;i<=n;i++){
		dp[i]=max(b[s[i]],dp[max(0,i-1)]);
		b[k^s[i]]=max(b[k^s[i]],dp[i]+1);
	}
	printf("%lld",dp[n]);
	return 0;
}
