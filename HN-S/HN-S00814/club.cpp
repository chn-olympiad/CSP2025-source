#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
//#define __Debug

using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
 
int t, n;
int ans;
int bucket[N];

#ifdef __Debug
int chose[N];
#endif

struct Node {
	int val, id;
	bool operator<(const Node &srca)const{
		return val > srca.val;
	}
	#ifdef __Debug
	int iid;
	#endif
};

Node a[N][3], b[N];

void Init() {
	memset(b, 0, sizeof(b));
	memset(bucket, 0, sizeof(bucket));
	#ifdef __Debug
	memset(chose, 0, sizeof(chose));
	#endif
	ans = 0;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		Init();
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j].val;
				a[i][j].id = j;
			}
			sort(a[i] + 1, a[i] + 4);
			b[i].val = a[i][2].val - a[i][1].val;
			b[i].id = a[i][1].id;
			#ifdef __Debug
			b[i].iid = i;
			#endif
			bucket[a[i][1].id]++;
			ans += a[i][1].val;
			#ifdef __Debug
			chose[i] = a[i][1].id;
			printf("b[%d]: val=%d id=%d\n", i, b[i].val, b[i].id);
			#endif
		}
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= 3; i++) {
			if (bucket[i] > n / 2) {
				int cnt = bucket[i] - (n / 2);
				for (int j = 1; j <= n; j++) {
					if (b[j].id == i) {
						#ifdef __Debug
						chose[i] = a[b[i].iid][bi];
						#endif
						ans += b[j].val;
						cnt--;
					}
					if (cnt == 0) break;
				}
			}
		}
		printf("%d\n", ans);
		
	}
	return 0;
}

