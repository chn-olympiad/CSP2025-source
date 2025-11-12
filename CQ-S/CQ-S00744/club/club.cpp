#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define fir first 
#define se second
using namespace std;
const ll N=1e5+10;
struct node { ll v,id; };
bool cmp(node x,node y)
{ return x.v>y.v; }
ll n,m,t,a[N][4],cnt[4],res;
void dfs(ll id,ll d1,ll d2,ll d3) {
	if(id==n+1) {
		res=max(res,d1+d2+d3);
		return ;
	}
	if(cnt[1]<n/2) {
		cnt[1]++;
		dfs(id+1,d1+a[id][1],d2,d3);
		cnt[1]--;
	}
	if(cnt[2]<n/2) {
		cnt[2]++;
		dfs(id+1,d1,d2+a[id][2],d3);
		cnt[2]--;
	}
	if(cnt[3]<n/2) {
		cnt[3]++;
		dfs(id+1,d1,d2,d3+a[id][3]);
		cnt[3]--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&n);
		cnt[0]=cnt[1]=cnt[2]=cnt[3]=res=0;
		for(ll i=1;i<=n;i++) {
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		if(n<=15) {
			dfs(1,0,0,0);
			printf("%lld\n",res);
			continue ;
		}
//		priority_queue <pii,vector<pii>,greater<pii>> q[4];
		priority_queue <pii> q[4];
		for(ll i=1;i<=n;i++) {
			ll f[4][4];
			for(ll j=1;j<=3;j++) {
				for(ll k=1;k<=3;k++) {
					f[j][k]=-2e9;
				}
			}
			for(ll j=1;j<=3;j++) {
				if((ll)q[j].size()<n/2) {
					f[j][j]=a[i][j];
				} else {
					ll val=q[j].top().fir;
					ll idr=q[j].top().se;
					for(ll k=1;k<=3;k++) {
						if(k!=j && (ll)q[k].size()<n/2) {
							f[j][k]=a[idr][k]-val+a[i][j];
						}
					}
				}
			}
			ll l=1,r=1;
			for(ll j=1;j<=3;j++) {
				for(ll k=1;k<=3;k++) {
//					printf("%d ",f[j][k]);
					if(f[l][r]<f[j][k]) {
						l=j,r=k;
					}
				}
//				puts("");
			}
			if(l==r) {
//				printf("1:q[%d].push :%d\n",l,i);
				q[l].push({f[l][l],i});
			} else {
				pii tp=q[l].top();
				q[r].push({a[tp.se][r],tp.se});
				q[l].pop();
				q[l].push({a[i][l],i});
//				printf("2:q[%d].push :%d\n",l,i);
			}
		} res=0;
//		printf("1:");
		while(!q[1].empty()) {
			ll id=q[1].top().se;
			res+=a[id][1];
//			printf("%d ",id);
			q[1].pop();
		}
//		printf("2:");
		while(!q[2].empty()) {
			ll id=q[2].top().se;
			res+=a[id][2];
//			printf("%d ",id);
			q[2].pop();
		}
//		printf("3:");
		while(!q[3].empty()) {
			ll id=q[3].top().se;
			res+=a[id][3];
//			printf("%d ",id);
			q[3].pop();
		} 
//		puts("");
		printf("%lld\n",res);
	}
	return 0;
}
/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
4
4 0 0
2 0 0
10 0 0
7 0 0

*/
