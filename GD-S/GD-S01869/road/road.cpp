#include <bits/stdc++.h>
using namespace std;

struct edge_ {
	int x,y,z;
} ed[1145141];

bool cmp(edge_ x,edge_ y) {
	return x.z < y.z;
}

int popcnt(int x) {
	int cnt = 0;
	while (x) {
		x -= x & -x;
		cnt++;
	}
	return cnt;
}

int n,m,k,a[10005],b[15][10005];
int f[11451],mn[11451][15],vis[11451];
vector <int> cp[11451];
int cur = 0;

int fd(int x) {
	if (f[x] == x) return x;
	return f[x] = fd(f[x]);
}

void merge(int x,int y) {
	int xx = fd(x),yy = fd(y);
	if (xx != yy) {
		f[xx] = yy;
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		ed[++cur] = {x,y,z};
	}
	for (int i = 1; i <= n + k; i++) f[i] = i;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
			ed[++cur] = {i + n,j,b[i][j]};
		}
	}
	sort(ed + 1,ed + cur + 1,cmp);
	int ans = 0;
//	for (int i = 1; i <= k; i++) {
//		for (int j = 1; j < cp[i].size(); j++) {
//			int xx = fd(cp[i][j - 1]),yy = fd(cp[i][j]);
//			if (xx != yy) {
//				f[xx] = yy;
//			}
//		}
//	}
	int res = 0;
	int c = 0,e = 0;
	for (int i = 1; i <= cur; i++) {
		if (e == n + k - 1) {
			break;
		}
		int x = fd(ed[i].x),y = fd(ed[i].y);
		if (x != y) {
			f[x] = y;
			c += ed[i].z;
			e++;
		}
	}
//	}
	cout << c;
	return 0;
}

//luogu uid:723036
// Genshin Genshin Genshin
// Impact Impact Impact
// just left 1hour,ping mu qian de xiao peng you men,ni jue de wo neng xie wan T2 ma? 
// 18:22 : yv gu 100 + 24 + 25 + 28 = 174 pts. AFO.
