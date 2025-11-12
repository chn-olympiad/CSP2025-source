#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
bool vis[MAXN];
ll f[MAXN];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	scanf("%lld%lld",&n,&k);
	ll ans=0;
	for(ll i = 1;i<=n;i++){
		scanf("%d",&f[i]);
	}ll sum;
	for(ll i = 1;i<=n;i++){
		sum=0;
		for(ll j = i;j<=n;j++){
			if(!vis[j]){
				sum=sum^f[j];
				if(sum==k){
					ans++;
					for(int p = i;p<=j;p++)vis[p]=1;
					break;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}