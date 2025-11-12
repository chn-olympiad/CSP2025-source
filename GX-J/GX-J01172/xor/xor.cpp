#include <bits/stdc++.h>
#define GXOI good
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], ans;
struct s {
	int left, right;
}b[N];
int top;
bool cmp (s x, s y) {
	if (x.left != y.left)
		return x.left < y.left;
	else
		return x.right < y.right;
}
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];		
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 1; j <= n; j ++) {
			int l = j;
			int r = j + i;
			if (r > n)
				break;			
			if (l == r && a[l] == k) {
				top ++;
				b[top].left = l;
				b[top].right = r;
			}
			else {
				int sum = a[l];
				for (int k = l + 1; k <= r; k ++)
					sum = (int) (sum ^ a[k]);
				if (sum == k) {
					top ++;
					b[top].left = l;
					b[top].right = r;
				}
			}
		}
	}
	sort (b + 1, b + top + 1, cmp);
	//for (int i = 1; i <= top; i ++)
	//	cout << b[i].left << " " << b[i].right << endl;
	int nowr = 0;
	for (int i = 1; i <= top; i ++)
		if (b[i].left > nowr) {
			ans ++;
			nowr = b[i].right;
		}
	cout << ans;
	return 0;
}
