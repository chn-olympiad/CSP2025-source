#include<bits/stdc++.h>
#define FL(i,a,b) for(ll i=(a);i<=(b);i++)
#define FR(i,a,b) for(ll i=(a);i>=(b);i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define PII pair<ll,ll> 
using namespace std;
const ll MAXN = 1e5 + 10;

ll n;
ll ans=0;
ll a[MAXN][4];
ll cnt[4];
ll q[4][MAXN];

bool cmp(ll p,ll q){
	return a[p][0]>a[q][0];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club4.in","r",stdin);
//	freopen("club.txt","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n),ans=0;
		FL(i,1,3) cnt[i]=0;
		FL(i,1,n){
			ll mx=0;
			FL(j,1,3) scanf("%lld",&a[i][j]),mx=max(mx,a[i][j]);
			FL(j,1,3){
				if(a[i][j]==mx){
					q[j][++cnt[j]]=i;
					ans+=a[i][j];
					break;
				}
			}
			sort(a[i]+1,a[i]+3+1);
			a[i][0]=a[i][3]-a[i][2]; 
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		ll id=0;
		FL(i,1,3) if(cnt[i]>n/2) id=i;
		sort(q[id]+1,q[id]+cnt[id]+1,cmp);
		FL(i,n/2+1,cnt[id]) ans-=a[q[id][i]][0];
		printf("%lld\n",ans);	
	}
	return 0;
}
