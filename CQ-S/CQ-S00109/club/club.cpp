#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int Maxn = 1e5+5;

namespace Josh_zmf {

	int N, M, a[Maxn][3], b[Maxn], cnt[5];
	vector <int> have[3];

	int main() {
		cin>> N;
		int ans = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		have[0].clear(), have[1].clear(), have[2].clear();
		for(int i=1; i<=N; i++) {
			cin>> a[i][0]>> a[i][1]>> a[i][2];
			if(a[i][0] >= max(a[i][1], a[i][2])) {
				cnt[0]++, ans += a[i][0];
				have[0].push_back(i);
			} else if(a[i][1] >= max(a[i][0], a[i][2])) {
				cnt[1]++, ans += a[i][1];
				have[1].push_back(i);
			} else {
				cnt[2]++, ans += a[i][2];
				have[2].push_back(i);
			}
		}
		int id = (cnt[0]>N/2 ?0 :(cnt[1]>N/2 ?1 :(cnt[2]>N/2 ?2 :-1)));
		if(id == -1)	return cout<< ans<< '\n', 0;
		M = 0;
		for(int i: have[id]) {
//			h.push_back({max(a[i][(id+1)%3], a[i][(id+2)%3]), i});
			b[++M] = max(a[i][(id+1)%3], a[i][(id+2)%3])-a[i][id];
		}
		sort(b+1, b+1+M, greater<int>());
		for(int i=1; i<=M and cnt[id]>N/2; i++, cnt[id]--) {
			ans += b[i];
		}
		cout<< ans<< '\n';
		return 0;
	}

}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T; cin>> T;
	while(T--)	Josh_zmf::main();
	return 0;
}
/*
1
2
10 9 8
4 0 0

*/
