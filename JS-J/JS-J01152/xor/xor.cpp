#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,lst[5000005],cnt[500005],dp[500005],pre[500005],candybar[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);for(int i=1,x;i<=n;i++)scanf("%lld",&x),candybar[i]=x^candybar[i-1];
	cnt[0]=1;for(int i=1;i<=n;i++){
		if(cnt[k^candybar[i]])dp[i]=pre[lst[k^candybar[i]]]+1;
		lst[candybar[i]]=i;
		pre[i]=max(pre[i-1],dp[i]);
		cnt[candybar[i]]++;
	}
	return printf("%lld\n",pre[n]),0;
}
