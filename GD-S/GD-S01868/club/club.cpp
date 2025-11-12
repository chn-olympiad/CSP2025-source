#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn][3],id[3];
inline void sol() {
	priority_queue<int> vec[3];
	int n; cin>>n;
	ll ans=0;
	for(int i=1;i<=n;++i) {
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		id[0]=0; id[1]=1; id[2]=2;
		sort(id,id+3,[&](int x,int y){return a[i][x]>a[i][y];});
		ans+=a[i][id[0]];
		vec[id[0]].push(a[i][id[1]]-a[i][id[0]]);
	}
	int h=n/2;
	while(vec[0].size()>h) {
		ans+=vec[0].top(); vec[0].pop();
	}
	while(vec[1].size()>h) {
		ans+=vec[1].top(); vec[1].pop();
	}
	while(vec[2].size()>h) {
		ans+=vec[2].top(); vec[2].pop();
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T; cin>>T; while(T--) sol();
	return 0;
}
