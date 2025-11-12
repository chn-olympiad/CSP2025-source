#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

template<typename T>
void read(T& x) {
	x = 0;
	char c;
	while(!isdigit(c = getchar()));
	do
		x = x * 10 + (c ^ 48);
	while(isdigit(c = getchar()));
}

int T, N, a[100005][3];
bool vis[100005];

priority_queue< int, vector<int>, greater<int> > Q[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(T);
	while(T --) {
		int ans = 0;
		read(N);
		for(int i = 1; i <= N; i ++) {
			for(int j = 0; j < 3; j ++)
				read(a[i][j]);
			ans += max(max(a[i][0], a[i][1]), a[i][2]);
			if(a[i][0] != a[i][1] || a[i][1] != a[i][2] || a[i][2] != a[i][0])
				if(a[i][0] > a[i][1] && a[i][0] > a[i][2])
					Q[0].push(a[i][0] - max(a[i][1], a[i][2]));
				else if(a[i][1] > a[i][2])
					Q[1].push(a[i][1] - max(a[i][0], a[i][2]));
				else
					Q[2].push(a[i][2] - max(a[i][0], a[i][1]));
		}
		for(int i = 0; i < 3; i ++)
			while(Q[i].size() > N / 2) {
				ans -= Q[i].top();
				Q[i].pop();
			}
		printf("%d\n", ans);
		for(int i = 0; i < 3; i ++)
			while(!Q[i].empty())
				Q[i].pop();
	}
	return 0;
}
