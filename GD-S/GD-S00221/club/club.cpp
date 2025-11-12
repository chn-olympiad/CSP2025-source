#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,cnt1,cnt2,cnt3,a[100005][5],ans;
priority_queue<int> q[5];
void solve(){
	scanf("%lld",&n),ans=cnt1=cnt2=cnt3=0;
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	while(!q[3].empty()) q[3].pop();
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	for(int i=1;i<=n;i++){
		int Max=max(a[i][1],max(a[i][2],a[i][3]));
		ans+=Max;
		if(a[i][1]==Max) cnt1++,q[1].push(max(a[i][2],a[i][3])-a[i][1]);
		else if(a[i][2]==Max) cnt2++,q[2].push(max(a[i][1],a[i][3])-a[i][2]);
		else cnt3++,q[3].push(max(a[i][1],a[i][2])-a[i][3]);
	}
	while(cnt1>(n/2)) ans+=q[1].top(),q[1].pop(),cnt1--;
	while(cnt2>(n/2)) ans+=q[2].top(),q[2].pop(),cnt2--;
	while(cnt3>(n/2)) ans+=q[3].top(),q[3].pop(),cnt3--;
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) solve();
	return 0;
}
