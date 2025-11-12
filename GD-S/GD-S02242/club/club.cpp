#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e5 + 10;
ll a, b, c, n, t, f1, f2, f3, mt[N][4];
vector<ll> p1, p2, p3;

void init() {
	p1.clear();
	p2.clear();
	p3.clear();
	a = b = c = f1 = f2 = f3 = 0;
}

bool cmp1(ll x, ll y) {
	if (mt[x][1] - max(mt[x][2], mt[x][3]) > mt[y][1] - max(mt[y][2], mt[y][3])) return true;
	return false;
}

bool cmp2(ll x, ll y) {
	if (mt[x][2] - max(mt[x][1], mt[x][3]) > mt[y][2] - max(mt[y][1], mt[y][3])) return true;
	return false;
}

bool cmp3(ll x, ll y) {
	if (mt[x][3] - max(mt[x][1], mt[x][2]) > mt[y][3] - max(mt[y][1], mt[y][2])) return true;
	return false;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		init();
		cin >> n;
		for (ll i = 1;i <= n;++i) cin >> mt[i][1] >> mt[i][2] >> mt[i][3];
		for (ll i = 1;i <= n;++i) {
			if (mt[i][1] == max({mt[i][1], mt[i][2], mt[i][3]})) p1.push_back(i), ++a, f1 += mt[i][1];
			else if (mt[i][2] == max({mt[i][1], mt[i][2], mt[i][3]})) p2.push_back(i), ++b, f2 += mt[i][2];
			else p3.push_back(i), ++c, f3 += mt[i][3];
		}
		ll w = n >> 1;
		if (a <= w && b <= w && c <= w) {
			cout << (f1 + f2 + f3) << '\n';
			continue;
		}
		if (a > w) {
			sort(p1.begin(), p1.end(), cmp1);
			while (a > w) {
				--a;
				ll k = p1[p1.size() - 1];
				p1.pop_back();
				f1 -= mt[k][1];
				if (mt[k][2] > mt[k][3]) f2 += mt[k][2];
				else f3 += mt[k][3];
			}
		}
		else if (b > w) {
			sort(p2.begin(), p2.end(), cmp2);
			while (b > w) {
				--b;
				ll k = p2[p2.size() - 1];
				p2.pop_back();
				f2 -= mt[k][2];
				if (mt[k][1] > mt[k][3]) f1 += mt[k][1];
				else f3 += mt[k][3];
			}
		}
		else {
			sort(p3.begin(), p3.end(), cmp3);
			while (c > w) {
				--c;
				ll k = p3[p3.size() - 1];
				p3.pop_back();
				f3 -= mt[k][3];
				if (mt[k][1] > mt[k][2]) f1 += mt[k][1];
				else f2 += mt[k][2];
			}
		}
		cout << (f1 + f2 + f3) << '\n';
	}
	return 0;
}

/*
if no restriction about n/2: all in the favourite
So if want to suit it, change less than n/2 people
Record 3:
1. favourite
2. more to 2
3. more to 3
Obviously, there is only 1 possible department which owns more than n/2 people
15:54: AC all 5 testcases, hope to a real AC
CCF Checker is more avaliable than the morning one, as it can check if the file dir is correct now
But why is there more than 100 lines for T1?
*/
