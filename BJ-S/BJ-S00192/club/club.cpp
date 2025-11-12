#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define N 100010
using namespace std;
int T,n,a[N][4];
struct Node{
	int id,p;
	bool operator<(const Node &__) const {
		return p>__.p;
	}
};
priority_queue<Node> v[4];
int main(void) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (;T--;) {
		cin >> n;
		for (int i=1;i<=n;i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int c1=max(a[i][1],max(a[i][2],a[i][3])),c2;
			
			if (c1==a[i][1]) c2=max(a[i][2],a[i][3]);
			else if (c1==a[i][2]) c2=max(a[i][1],a[i][3]);
			else if (c1==a[i][3]) c2=max(a[i][1],a[i][2]);
			
			if (c1==a[i][1]) v[1].push(Node{i,c1-c2});
			else if (c1==a[i][2]) v[2].push(Node{i,c1-c2});
			else if (c1==a[i][3]) v[3].push(Node{i,c1-c2});
			
			if ((int)(v[1].size())>(n/2)) {
				Node tp=v[1].top();
				v[1].pop();
				int idd=tp.id;
				if (a[idd][2]>=a[idd][3]) v[2].push(Node{idd,a[idd][2]-a[idd][3]});
				if (a[idd][2]<a[idd][3]) v[3].push(Node{idd,a[idd][3]-a[idd][2]});
			}
			if ((int)(v[2].size())>(n/2)) {
				Node tp=v[2].top();
				v[2].pop();
				int idd=tp.id;
				if (a[idd][1]>=a[idd][3]) v[1].push(Node{idd,a[idd][1]-a[idd][3]});
				if (a[idd][1]<a[idd][3]) v[3].push(Node{idd,a[idd][3]-a[idd][1]});
			}
			if ((int)(v[3].size())>(n/2)) {
				Node tp=v[3].top();
				v[3].pop();
				int idd=tp.id;
				if (a[idd][1]>=a[idd][2]) v[1].push(Node{idd,a[idd][1]-a[idd][2]});
				if (a[idd][1]<a[idd][2]) v[2].push(Node{idd,a[idd][2]-a[idd][1]});
			}
		}
		int ans=0;
		for (;!v[1].empty();) {
			ans+=a[v[1].top().id][1];
			v[1].pop();
		}
		for (;!v[2].empty();) {
			ans+=a[v[2].top().id][2];
			v[2].pop();
		}
		for (;!v[3].empty();) {
			ans+=a[v[3].top().id][3];
			v[3].pop();
		}
		cout << ans << endl;
	}
	return 0;
}