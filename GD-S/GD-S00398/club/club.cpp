#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

void solve();
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
ll n;
struct node {
	ll v[3];
	ll max_id;ll x,y,z;
	ll cha;
	void readin() {
		cin>>v[0]>>v[1]>>v[2];
		x=v[0];y=v[1];z=v[2];
		sort(v,v+3);
		cha = v[2]-v[1];
		if(v[2] == x) max_id = 0;
		if(v[2] == y) max_id = 1;
		if(v[2] == z) max_id = 2;
	}
};
	inline bool operator < (const node me,const node another) {
		return me.cha > another.cha;
	}
node a[maxn];
priority_queue<node> tong[3];
void solve() {
	cin>>n;
	ll ans(0);
	for(ll i = 0; i<n; ++i) {
		a[i].readin();
		tong[a[i].max_id].push(a[i]);
		ans += a[i].v[2];
	}
	for(ll i =0;i<3;++i) while(tong[i].size() > (n >> 1)) {
		ans -= tong[i].top().cha;
		tong[i].pop();
	}
	cout<<ans<<endl;
}
/*

1 4 
4 2 1 
3 2 4 
5 3 4 
3 5 1

*/
