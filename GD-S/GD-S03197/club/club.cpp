#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<ll,ll>
#define ve vector<ll>
#define mid ((l+r)>>1)
#define lx (x<<1)
#define rx (x<<1|1)
using namespace std;
const ll N=2e5+2;
ll T,n,m,ans,a[N][3];
vector<ll>e[3];
void slv(){
	cin>>n,ans=0;
	for(ll i=0;i<3;i++)e[i].clear();
	for(ll i=1,x,y,z,w,d,v;i<=n;i++){
		cin>>x>>y>>z;
		w=max(max(x,y),z);
		d=(x==w?0:(y==w?1:2));
		v=w-(!d?max(y,z):(d==1?max(x,z):max(x,y)));
		ans+=w,e[d].pb(v);
	}
	for(ll i=0;i<3;i++){
		sort(e[i].begin(),e[i].end(),greater<ll>());
		while(e[i].size()>(n>>1))
			ans-=e[i].back(),e[i].pop_back();
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)slv(); 
	return 0;
}
