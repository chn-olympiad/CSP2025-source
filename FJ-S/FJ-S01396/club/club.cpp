#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100005][5],vis[100005],buc[5],maxm,ans,p[100005],cnt;
ll cmp1(ll x,ll y,ll z){
	ll ret = max(x,max(y,z));
	if(ret == x)return 1;
	if(ret == y)return 2;
	return 3;
}
ll cmp2(ll x,ll y,ll z){
	ll temp[5];
	temp[1] = x,temp[2] = y,temp[3] = z;
	sort(temp + 1,temp + 4);
	return temp[2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(ll i = 1;i <= t;i++){
		memset(buc,0,sizeof(buc));
		scanf("%lld",&n);
		ans = 0,cnt = 0;
		for(ll j = 1;j <= n;j++){
			scanf("%lld%lld%lld",&a[j][1],&a[j][2],&a[j][3]);
			vis[j] = cmp1(a[j][1],a[j][2],a[j][3]),buc[vis[j]]++,ans += a[j][vis[j]];
		}
		maxm = cmp1(buc[1],buc[2],buc[3]);
		for(ll j = 1;j <= n;j++)if(vis[j] == maxm)cnt++;
		if(cnt <= n / 2){
			printf("%lld\n",ans);
			continue;
		}
		for(ll j = 1;j <= n;j++){
			if(vis[j] != maxm)p[j] = 2147483647;
			else p[j] = a[j][vis[j]] - cmp2(a[j][1],a[j][2],a[j][3]);
		}
		sort(p + 1,p + n + 1);
		for(ll j = n / 2 + 1;j <= cnt;j++)ans -= p[j - n / 2];
		printf("%lld\n",ans);
	}
	return 0;
}
