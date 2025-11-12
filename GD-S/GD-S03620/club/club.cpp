#include <iostream>
#include <queue>
using namespace std;
const int N=100005;
int n,a[N][4];
priority_queue<int> pq[4];
void solve() {
	cin>>n;
	for(int i=1;i<=3;i++) {
		while(pq[i].size())
			pq[i].pop();
	}
	int ans=0;
	for(int i=1;i<=n;i++) {
		int mx=0,mx2=0;
		for(int j=1;j<=3;j++) {
			cin>>a[i][j];
			if(!mx||a[i][mx]<a[i][j]) {
				mx2=mx;
				mx=j;
			} else if(!mx2||a[i][mx2]<a[i][j])
				mx2=j;
		}
		pq[mx].push(a[i][mx2]-a[i][mx]);
		ans+=a[i][mx];
	}
	for(int i=1;i<=3;i++) {
		while(pq[i].size()>(n>>1)) {
			ans+=pq[i].top();
			pq[i].pop();
		}
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}

