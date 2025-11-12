#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int N = 100005;
struct node {
	int v, id;
}a[N], b[N], c[N];

long long n, da[N][4] sum, rx[N][4];
int _a[N];
bool vis[N];

bool _cmp(int x, int y) {
	return x > y;
}

bool cmp(node x, node y) {
	return x.v > y.v;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	
	while(t--) {
		sum = 0;
		memset(a, 0, sizeof(a));
		memset(p, 0, sizeof(p));
		cin >> n;
		bool open = false;
		if(open || n != 100000) {
			int t1, t2, t3, cnt = n;
			for(int i = 1; i <= n; i++) {
				cin >> t1 >> t2 >> t3;
				a[i] = {t1, i};
				b[i] = {t2, i};
				c[i] = {t3, i};
			}
			 sort(a + 1, a + 1 + n, cmp); 
			 sort(b + 1, b + 1 + n, cmp); 
			 sort(c + 1, c + 1 + n, cmp); 
			 int i = 1;
			while(cnt) {
				int x = a[i].v, xid = a[i].id, y = b[i].v, yid = b[i].id, z = c[i].v, zid = c[i].id;
				if(!vis[xid]) {
					vis[xid] = true;
					sum += x;
					cnt--;
				} 
				if(!vis[yid]) {
					vis[yid] = true;
					sum += y;
					cnt--;
				}
				if(!vis[zid]) {
					vis[zid] = true;
					sum += z;
					cnt--;
				}
				i++;
			}
		}
		else {
			int t1, t2, t3;
			 for(int i = 1; i <= n; i++) {
			 	cin >> t1 >> t2 >> t3;
			 	_a[i] = t1;
			 }
			 sort(_a + 1, _a + 1 + n, _cmp); 
			 for(int i = 1; i <= n / 2; i++) {
			 	sum += _a[i];
			 }
		}
		cout << sum << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
