#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,k;
int a[N],sum[N];
int ans=0;
int vis[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k) ans++;
		sum[i]=sum[i-1]^a[i];
	}
	int now=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			now=i;
			continue;
		}
		for(int r=i;r<=n;r++){
			if(a[r]==k) break;
			if((sum[i-1]^sum[r])==k&&(r<now||i>now)){
				if(i>now) ans++;
				now=r;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
