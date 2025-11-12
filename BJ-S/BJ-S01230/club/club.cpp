// Calm down.
// Think TWICE, code ONCE.
#include<bits/stdc++.h>
#define pb push_back
#define popcnt __builtin_popcountll
#define debug printf("Passed line %d\n", __LINE__)

using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
	x = 0; bool F = 0; char c = getchar();
	for (;!isdigit(c);c = getchar()) F |= (c == '-');
	for (;isdigit(c);c = getchar()) x = x*10+(c^48);
	if (F) x = -x;
}

template<typename T1, typename ...T2> inline void read(T1 &x, T2 &...y){read(x), read(y...);}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

priority_queue<int> q[5];
int a[5], n;

inline void solve(){
	for (int i = 0;i<3;i++) while (q[i].size()) q[i].pop();
	read(n); int t, v, ans = 0;
	for (int i = 1;i<=n;i++){
		t = 0;
		for (int j = 0;j<3;j++){
			read(a[j]);
			if (a[j]>a[t]) t = j;
		}
		v = -1e9;
		for (int j = 0;j<3;j++) if (j!=t) checkmax(v, a[j]-a[t]);
		q[t].push(v), ans += a[t];
	}
	for (int i = 0;i<3;i++){
		while (q[i].size()>n/2) ans += q[i].top(), q[i].pop();
	}
	printf("%d\n", ans);
}

int main(){
	// freopen("input.txt", "r", stdin); cerr << "----------------------------------- Program output -----------------------------------\n";
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; read(t); while (t--) solve();
	return 0;
}
/*
self check:
1. freopen
2. long long
3. size of array
4. code for testing
*/