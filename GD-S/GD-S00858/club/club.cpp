#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define rep(t,l,r) for(int t=l;t<=r;t++)
#define per(t,l,r) for(int t=r;t>=l;t--)

using namespace std;
const int N=1e5+10;
int n;
ll a[N],b[N],c[N],d[N],rec[N],fir[N],sec[N];
bool cmp(int x,int y) {return d[x]<d[y];}

void solve() {
	cin>>n; 
	rep(i,1,n+5) d[i]=rec[i]=fir[i]=sec[i]=0;
	rep(i,1,n) cin>>a[i]>>b[i]>>c[i];
	ll ans=0,cnt[3]={0,0,0};
	rep(i,1,n) {
		pii tmp[3]={{a[i],0},{b[i],1},{c[i],2}};
		sort(tmp,tmp+3);
		fir[i]=tmp[2].se; sec[i]=tmp[1].se;
		ans+=tmp[2].fi; cnt[tmp[2].se]++;
		rec[i]=tmp[2].se;
		d[i]=tmp[2].fi-tmp[1].fi;
	}
	rep(i,0,2) if(cnt[i]>(n/2)) {
		vector<int> id;
		rep(j,1,n) if(rec[j]==i) id.push_back(j);
		sort(id.begin(),id.end(),cmp);
		rep(j,0,cnt[i]-(n/2)-1) ans-=d[id[j]];
	}
	cout<<ans<<"\n";
	return ;
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tc; cin>>tc; while(tc--) solve();	
	return 0;
}
