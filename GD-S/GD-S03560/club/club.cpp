#include<bits/stdc++.h>
#define ll long long
#define pair pair<int, int>

using namespace std;

const ll N = 1e5 + 10;

inline ll read(){
	char c = getchar(); ll x = 0, s = 1;
	while(!isdigit(c)) {
		if(c == '-') s = -1;
		c = getchar();
	}
	while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return s * x; 
}

int b[4][N];

bool cmp1(int x, int y) {
	return min(b[1][x] - b[2][x], b[1][x] - b[3][x]) < min(b[1][y] - b[2][y], b[1][y] - b[3][y]);
}

bool cmp2(int x, int y) {
	return b[2][x] - b[3][x] < b[2][y] - b[3][y];
}

int s1[N], s2[N], s3[N];

int t1, t2, t3, n;

int solve() {
	int res = 0;
	if(t2 >= n / 2) swap(s1, s2), swap(t1, t2), swap(b[1], b[2]);
	else if(t3 >= n / 2) swap(s1, s3), swap(t1, t3), swap(b[1], b[3]);
	sort(s1 + 1, s1 + t1 + 1, cmp1);
	for(int i = 1; i <= t1 - (n / 2); ++i) {
		int x = s1[i];
		if(min(b[1][x] - b[2][x], b[1][x] - b[3][x]) == b[1][x] - b[2][x]) {
			s2[++t2] = x;
			res += b[1][x] - b[2][x];
		}
		else {
			s3[++t3] = x;
			res += b[1][x] - b[3][x];
		}
	}
	if(t2 < t3) swap(s3, s2), swap(t3, t2), swap(b[3], b[2]);
	if(t2 > (n / 2)) {
		sort(s2 + 1, s2 + t2 + 1, cmp2);
		for(int i = 1; i <= t2 - (n / 2); ++i) {
			int x = s2[i];
			res += b[2][x] - b[3][x];
		}
		return res;
	}
	else return res;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while(T --) {
		t1 = t2 = t3 = 0;
		n = read();
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			b[1][i] = read();
			b[2][i] = read();
			b[3][i] = read();
			int mx = max(max(b[1][i], b[2][i]), b[3][i]);
			if(mx == b[1][i]) s1[++t1] = i;
			else if(mx == b[2][i]) s2[++t2] = i;
			else if(mx == b[3][i]) s3[++t3] = i;
			ans += mx;
		}
		if(t1 <= (n /2) && t2 <= (n /2) && t3 <= (n / 2)) printf("%d\n", ans);
		else printf("%d\n", ans - solve());
	}
	
	return 0;
}



