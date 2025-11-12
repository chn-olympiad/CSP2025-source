// godmoo's code
#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define ep emplace
#define fi first
#define se second
#define lbd lower_bound
#define ubd upper_bound
#define mathmod(a, m) (((a) % (m) + (m)) % (m))
#define all(a) (a).begin(), (a).end()
typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii;

const int N = 1e5 + 5;
int n, vis[N];
struct Node {
	int a, b, c;
} a[N];
vector<int> Va, Vb, Vc;

struct Ele {
	int id, diff;
	Ele(int _id = 0, int _diff = 0): id(_id), diff(_diff) {} 
	bool operator < (const Ele &rhs) const {
		return diff > rhs.diff;
	} bool operator > (const Ele &rhs) const {
		return diff < rhs.diff; 
	}
};

void solve() {
	cin >> n;
	int S = 0;
	Va.resize(0), Vb.resize(0), Vc.resize(0);
	for(int i = 1; i <= n; i++){
		cin >> a[i].a >> a[i].b >> a[i].c, vis[i] = 0;
		int mx = max({a[i].a, a[i].b, a[i].c});
		S += mx;
		if(a[i].a == mx) Va.eb(i);
		else if(a[i].b == mx) Vb.eb(i);
		else if(a[i].c == mx) Vc.eb(i);
		else assert(0);
	}
	if((int)Va.size() > n >> 1){
		int d = (int)Va.size() - (n >> 1);
		priority_queue<Ele> B, C;
		for(int i : Va) B.ep(i, a[i].a - a[i].b), C.ep(i, a[i].a - a[i].c);
		while(d--) {
			Ele u;
			if(B.top() > C.top()) {
				u = B.top(); B.pop();
			} else {
				u = C.top(); C.pop();
			}
			if(vis[u.id]) d++;
			else vis[u.id] = 1, S -= u.diff;
		}
	} else if((int)Vb.size() > n >> 1) {
		int d = (int)Vb.size() - (n >> 1);
		priority_queue<Ele> A, C;
		for(int i : Vb) A.ep(i, a[i].b - a[i].a), C.ep(i, a[i].b - a[i].c);
		while(d--) {
			Ele u;
			if(A.top() > C.top()) {
				u = A.top(); A.pop();
			} else {
				u = C.top(); C.pop();
			}
			if(vis[u.id]) d++;
			else vis[u.id] = 1, S -= u.diff;
		}
	} else if((int)Vc.size() > n >> 1) {
		int d = (int)Vc.size() - (n >> 1);
		priority_queue<Ele> A, B;
		for(int i : Vc) A.ep(i, a[i].c - a[i].a), B.ep(i, a[i].c - a[i].b);
		while(d--) {
			Ele u;
			if(A.top() > B.top()) {
				u = A.top(); A.pop();
			} else {
				u = B.top(); B.pop();
			}
			if(vis[u.id]) d++;
			else vis[u.id] = 1, S -= u.diff;
		}
	}
	cout << S << '\n';
}

#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

int main(){
	file(club);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for(int Cas, i = (cin >> Cas, 1); i <= Cas; i++) solve();
	cout << flush;
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
