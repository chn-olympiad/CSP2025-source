#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
using namespace std;
char Ch;
int ff;
void rd(int &x) {
	x=0,ff=1;
	Ch=getchar();
	while((Ch<'0' || Ch>'9') && Ch!='-') Ch=getchar();
	if(Ch=='-') ff=-1,Ch=getchar();
	while(Ch>='0' && Ch<='9') {
		x=(x<<1)+(x<<3)+Ch-'0';
		Ch=getchar();
	}
	x*=ff;
}
const int N=1e5+5;
int T,n;
int a[N][3];
vector<int> v[3];
ll ans;
void Solve() {
	ans=0;
	rd(n);
	v[0].clear();
	v[1].clear();
	v[2].clear();
	for(int i=1; i<=n; i++) {
		rd(a[i][0]),rd(a[i][1]),rd(a[i][2]);
		int mx=max({a[i][0],a[i][1],a[i][2]});
		ans+=mx;
		for(int j=0; j<3; j++)
			if(a[i][j]==mx)
				v[j].pb(i);
	}
	auto szmx=max({v[0].size(),v[1].size(),v[2].size()});
	int u=0;
	for(int i=0; i<3; i++)
		if(v[i].size()==szmx)
			u=i;
	vector<int> d;
	for(auto x:v[u]) {
		int w=0;
		for(int j=0; j<3; j++)
			if(j!=u) w=max(w,a[x][j]);
		d.pb(a[x][u]-w);
	}
	sort(d.begin(),d.end());
	int len=v[u].size()-n/2;
	for(int i=0; i<len; i++)
		ans-=d[i];
	printf("%lld\n",ans);
}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	rd(T);
	while(T--) Solve();
	return 0;
}

