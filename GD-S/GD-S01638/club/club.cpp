#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+10;

int a[N][4];
int b[4];
void slove() {
	memset(a,0,sizeof a);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=3;j++) {
			cin>>a[i][j];
		}
	}
	using pii = pair<int,int>; 
	priority_queue<pii>q[4];
	int cnt[4]; cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
	int ans = 0;
	for (int i=1;i<=n;i++) {
		int id[4];
		b[1] = a[i][1],b[2] = a[i][2],b[3] = a[i][3];
		iota(id,id+4,0);
		sort(id+1,id+3+1,[](int A,int B) {
			return b[A] < b[B];
		});
		q[id[3]].push({b[id[2]] - b[id[3]],id[2]});
		if (cnt[id[3]] == n / 2) {
			ans += b[id[3]] + q[id[3]].top().first;
			cnt[q[id[3]].top().second]++;
			q[id[3]].pop();
		}
		else {
			ans += b[id[3]];
			cnt[id[3]]++;
		}
	}
//	cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << endl;
	cout << ans << '\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr) -> sync_with_stdio(false); 
	int T;
	cin>>T;
	while(T--) {
		slove();
	}
	return 0;
} 
