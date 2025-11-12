#include <bits/stdc++.h>

using namespace std;

struct path {
	int start, end, fee, belongsTo;
};

bool cmp(path pa, path pb) {
	return (pa.fee < pb.fee);
}

//int n, m, k, u[1000010], v[1000010], w[1000010], c[12], a[12][10010];
int n, m, k, u, v, w, c[12], a, counter, res, amConnected;
bool connected[10010];
path ps[1000010], p;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	counter = 0;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		p.start = u - 1;
		p.end = v - 1;
		p.fee = w;
		p.belongsTo = -1;
		ps[counter++] = p;
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		for (int j = 0; j < n; j++) {
//			cin >> tmp[j];
			cin >> a;
//			a = tmp[j];//			if (i == 0 && j == 1) cout << a << endl;//			if (i == 0) cout << tmp[j] << endl;
			p.start = n + i + 1;
			p.end = j;
			p.fee = c[i] + a;
			p.belongsTo = i;
			ps[counter++] = p;
		}
	}
	sort(ps, ps + counter, cmp);
//	for (int k = 0; k < counter; k++) {//		cout << ps[k].start << ' ' << ps[k].end << ' ' << ps[k].fee << ' ' << ps[k].belongsTo << endl;//	}  // test
	res = 0;
	amConnected = 0;
//	connected[ps[0].start] = true;//	connected[ps[0].end] = true;//	res += ps[0].fee;
//	connected[ps[0].start] = true;
	for (int i = 0; i < counter; i++) {  // Kruskal?!
//		if (ps[i].fee == 5) {//			cout << ps[i].start << ' ' << ps[i].end << ' ' << ps[i].fee << ' ' << ps[i].belongsTo << endl;//			cout << (!(connected[ps[i].start] && connected[ps[i].end])) << endl;//		}
		if (!(connected[ps[i].start] && connected[ps[i].end])) {
			connected[ps[i].start] = true;
			connected[ps[i].end] = true;
			res += ps[i].fee;
//			cout << ps[i].start << ' ' << ps[i].end << ' ' << ps[i].fee << ' ' << ps[i].belongsTo << endl;
			if (++amConnected == n) {
				break;
			}
			if (ps[i].belongsTo != -1) {
				for (int j = i + 1; j < counter; j++) {
					if (ps[j].belongsTo == ps[i].belongsTo) {
						ps[j].fee -= c[ps[i].belongsTo];
						ps[j].belongsTo = -1;
					}
				}
//				cout << "--------------------\n";
//				for (int k = 0; k < counter; k++) {
//					cout << ps[k].start << ' ' << ps[k].end << ' ' << ps[k].fee << ' ' << ps[k].belongsTo << endl;
//				}  // test
//				cout << "--------------------\n";
			}
		}
	}
	cout << res << endl;
	return 0;
}
