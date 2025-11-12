#include <bits/stdc++.h>
using namespace std;
int cnt[4];
struct node {
	int n, m, q, maxn, maxn2, maxn3, id, id2, id3;
} a[100001];
int maxx(int x, int y, int z) {
	return max(max(x,y),max(y,z));
}
int minn(int x, int y, int z) {
	return min(min(x,y),min(y,z));
}
int max(int x, int y) {
	if (x > y) {
		return x;
	} else {
		return y;
	}
}
int min(int x, int y) {
	if (x < y) {
		return x;
	} else {
		return y;
	}
}
int maxx2(int x, int y, int z) {
	if ((x >= y && x <= z) || (x <= y && x >= z)) {
		return x;
	} else if ((y >= x && y <= z) || (y <= x && y >= z)) {
		return y;
	} else {
		return z;
	}
}
int find_id(int i) {
	if (a[i].n == a[i].maxn) {
		return 1;
	} else if (a[i].m == a[i].maxn) {
		return 2;
	} else {
		return 3;
	}
}
int find_id2(int i) {
	if (a[i].n == a[i].maxn2) {
		return 1;
	} else if (a[i].m == a[i].maxn2) {
		return 2;
	} else {
		return 3;
	}
}
int find_id3(int i) {
	if (a[i].n == a[i].maxn3) {
		return 1;
	} else if (a[i].m == a[i].maxn3) {
		return 2;
	} else {
		return 3;
	}
}
bool cmp(node x, node y) {
	if (x.maxn != y.maxn) {
		return x.maxn > y.maxn;
	} else if (x.maxn2 != y.maxn2) {
		return x.maxn2 > y.maxn2;
	} else {
		return x.maxn3 > y.maxn3;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--) {
		memset(cnt,0,sizeof(cnt));
		int n, ans = 0, sum = 0, num = 0, val = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].n >> a[i].m >> a[i].q;
			a[i].maxn = maxx(a[i].n,a[i].m,a[i].q);
			a[i].maxn2 = maxx2(a[i].n,a[i].m,a[i].q);
			a[i].maxn3 = minn(a[i].n,a[i].m,a[i].q);
			a[i].id = find_id(i);
			a[i].id2 = find_id2(i);
			a[i].id3 = find_id3(i);
		}
		sort(a + 1,a + n + 1,cmp);
		for (int i = 1; i <= n; i++) {
			if (cnt[a[i].id] < n / 2){
				ans += a[i].maxn;
				cnt[a[i].id]++;
			}else if (cnt[a[i].id2] < n / 2){
				ans += a[i].maxn2;
				cnt[a[i].id2]++;
			}else{
				ans += a[i].maxn3;
				cnt[a[i].id3]++;
			}
		}
//		for (int i = 1; i <= n; i++) {
//			if (cnt[a[i].id] < n / 2) {
//				sum += a[i].maxn;
//				cnt[a[i].id]++;
//			}
//			if (cnt[a[i].id2] < n / 2) {
//				num += a[i].maxn2;
//				cnt[a[i].id2]++;
//			}
//			if (cnt[a[i].id3] < n / 2) {
//				val += a[i].maxn3;
//				cnt[a[i].id3]++;
//			}
//		}
//		ans = maxx(sum + num,sum + val,num + val);
		cout << ans << endl;
	}
	return 0;
}
