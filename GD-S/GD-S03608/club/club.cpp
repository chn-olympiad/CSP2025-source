#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5;
struct node{
	int w1,w2,w3;
}a[N];
int maxn(int x,int y,int z){
	int p = max(x,y);p = max(p,z);
	return p;
}
vector<int>V[10];int n;
void solve(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d%d%d",&a[i].w1,&a[i].w2,&a[i].w3);
	int tot1 = 0,tot2 = 0,tot3 = 0;
	long long ans = 0;for(int i = 1;i<=3;i++) V[i].clear();
	for(int i = 1;i<=n;i++){
		int p = maxn(a[i].w1,a[i].w2,a[i].w3);
		ans += p;
		if(p==a[i].w1){
			tot1++;
			int p1 = a[i].w1-a[i].w2,p2 = a[i].w1-a[i].w3;
			V[1].pb(min(p1,p2));
		}
		else if(p==a[i].w2){
			tot2++;
			int p1 = a[i].w2-a[i].w1,p2 = a[i].w2-a[i].w3;
			V[2].pb(min(p1,p2));
		}
		else{
			tot3++;
			int p1 = a[i].w3-a[i].w1,p2 = a[i].w3-a[i].w2;
			V[3].pb(min(p1,p2));
		}
	}
	if(tot1<=n/2&&tot2<=n/3&&tot3<=n/2){
		printf("%lld\n",ans);
		return;
	}
	for(int i = 1;i<=3;i++) sort(V[i].begin(),V[i].end());
	int p,cnt;
	if(tot1>n/2) p = 1,cnt = tot1-n/2;
	else if(tot2>n/2) p = 2,cnt = tot2-n/2;
	else p = 3,cnt = tot3-n/2;
	for(int i = 0;i<cnt;i++) ans -= V[p][i];
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--) solve();
	return 0;
}
