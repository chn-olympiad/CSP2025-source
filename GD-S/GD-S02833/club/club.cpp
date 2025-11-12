#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;

const int M = 1e5 + 10;

struct Pos{
	int a[10], ta, ti;
	bool vis;
	Pos(int a1, int a2, int a3, int _ta, int _ti, int _vis) {
		a[1] = a1;
		a[2] = a2;
		a[3] = a3;
		ta = _ta;
		ti = _ti;
		vis = _vis;
	}
};

bool cmp1(Pos a, Pos b) {
	for (int i = 1; i <= 3; i++) {
		if (a.ta < a.a[i]) a.ta = a.a[i], a.ti = i;
		if (b.ta < b.a[i]) b.ta = b.a[i], b.ti = i;
	}
	return a.ta > b.ta;
}

bool cmp2(Pos a, Pos b) {
	int aat = max(a.a[1], max(a.a[2], a.a[3]));
	int abt = max(b.a[1], max(b.a[2], b.a[3]));
	int iat = min(a.a[1], min(a.a[2], a.a[3]));
	int ibt = min(b.a[1], min(b.a[2], b.a[3]));
	for (int i = 1; i <= 3; i++) {
		if (a.a[i] != aat and a.a[i] != iat) a.ta = a.a[i], a.ti = i;
		if (b.a[i] != abt and b.a[i] != ibt) b.ta = b.a[i], b.ti = i;
	}
	return a.ta > b.ta;
}

bool cmp3(Pos a, Pos b) {
	a.ta = 100000000;
	b.ta = 100000000;
	for (int i = 1; i <= 3; i++) {
		if (a.ta > a.a[i]) a.ta = a.a[i], a.ti = i;
		if (b.ta > b.a[i]) b.ta = b.a[i], b.ti = i;
	}
	return a.ta > b.ta;
}

int T;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		int n, ans[10][10] = {{0, 0}, {0, 0}, {0, 0}};
		vector <Pos> a;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			a.push_back(Pos(t1, t2, t3, 0, 0, false));
		}
		sort(a.begin(), a.end(), cmp1);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= 3; j++) 
				if (a[i].ta < a[i].a[j]) a[i].ta = a[i].a[j], a[i].ti = j;
			if (ans[a[i].ti][0] < (n / 2)) 
				ans[a[i].ti][0]++, ans[a[i].ti][1] += a[i].ta, a[i].vis = true;
		}
		sort(a.begin(), a.end(), cmp2);
		for (int i = 0; i < n; i++) {
			int aat = max(a[i].a[1], max(a[i].a[2], a[i].a[3]));
			int iat = min(a[i].a[1], min(a[i].a[2], a[i].a[3]));
			for (int j = 1; j <= 3; j++) 
				if (a[i].a[j] != aat and a[i].a[j] != iat) 
					a[i].ta = a[i].a[j], a[i].ti = j;
			if (a[i].vis) continue;
			if (ans[a[i].ti][0] < (n / 2)) 
				ans[a[i].ti][0]++, ans[a[i].ti][1] += a[i].ta, a[i].vis = true;
		}
		sort(a.begin(), a.end(), cmp3);
		for (int i = 0; i < n; i++) {
			a[i].ta = 100000000;
			for (int j = 1; j <= 3; j++) 
				if (a[i].ta > a[i].a[j]) a[i].ta = a[i].a[j], a[i].ti = j;
			if (a[i].vis) continue;
			if (ans[a[i].ti][0] < (n / 2)) 
				ans[a[i].ti][0]++, ans[a[i].ti][1] += a[i].ta, a[i].vis = true;
		}
		int num = 0;
		for (int i = 1; i <= 3; i++) 
			num += ans[i][1];
		cout << num << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
