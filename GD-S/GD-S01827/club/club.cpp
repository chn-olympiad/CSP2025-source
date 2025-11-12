#include<bits/stdc++.h>
#define max(x, y) (x > y? x : y)
#define int long long
using namespace std;
int n;
struct node {
	int a, b, c;
	int _;
	bool sa, sb, sc;
} a[100010];
int ans1, ans2, ans3;
int T;
bool cmp1(node A, node B) {
	return A.a - max(A.b, A.c) > B.a - max(B.b, B.c);
}
bool cmp2(node A, node B) {
	if(A.sa) return false;
	return A.b - A.c > B.b - B.c;
}
bool cmp3(node A, node B) {
	return A.b - max(A.a, A.c) > B.b - max(B.a, B.c);
}
bool cmp4(node A, node B) {
	if(A.sb) return false;
	return A.a - A.c > B.a - B.c;
}
bool cmp5(node A, node B) {
	return A.c - max(A.a, A.b) > B.c - max(B.a, B.b);
}
bool cmp6(node A, node B) {
	if(A.sc) return false;
	return A.a - A.b > B.a - B.b;
}
int t;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		ans1 = 0;
		ans2 = 0;
		ans3 = 0;
		for(int i = 1; i <= n; i++) {
//			cin >> a[i].a >> a[i].b >> a[i].c;
			scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c);
			a[i].sa = false;
			a[i].sb = false;
			a[i].sc = false;
			a[i]._ = i;
		}
//		cout << endl; 
		sort(a + 1, a + n + 1, cmp1);
		for(int i = 1; i <= n >> 1; i++) {
			if(a[i].a - max(a[i].b, a[i].c) >= 0) {
				ans1 += a[i].a;
//				cout << a[i]._ << " a " << a[i].a << endl;
				a[i].sa = true;
			} else {
				break;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		for(int i = 1; i <= n >> 1; i++) {
			if(a[i].sa) break;
			if(a[i].b - a[i].c >= 0) {
				ans1 += a[i].b;
//				cout << a[i]._ << " b " << a[i].b << endl;
				a[i].sb = true;
			} else {
				break;
			}
		}
		t = 1;
		for(int i = 1; i <= n >> 1; i++) {
			while(a[t].sa || a[t].sb) {
				++t;
				if(t > n) break;
			}
			if(t > n) break;
			ans1 += a[t].c;
//			cout << a[t]._ << " c " << a[t].c << ' ' << a[t].sa << ' ' << a[t].sb << endl;
			++t;
		}
//		cout << ans1 << endl;
		//------------------------------------------------------------------------
		for(int i = 1; i <= n; i++) {
			a[i].sa = false;
			a[i].sb = false;
			a[i].sc = false;
		}
		sort(a + 1, a + n + 1, cmp3);
		for(int i = 1; i <= n >> 1; i++) {
			if(a[i].b - max(a[i].a, a[i].c) >= 0) {
				ans2 += a[i].b;
//				cout << a[i]._ << " b " << a[i].b << endl;
				a[i].sb = true;
			} else {
				break;
			}
		}
		sort(a + 1, a + n + 1, cmp4);
		for(int i = 1; i <= n >> 1; i++) {
			if(a[i].sb) break;
			if(a[i].a - a[i].c >= 0) {
				ans2 += a[i].a;
//				cout << a[i]._ << " a " << a[i].a << endl;
				a[i].sa = true;
			} else {
				break;
			}
		}
		t = 1;
		for(int i = 1; i <= n >> 1; i++) {
			while(a[t].sa || a[t].sb) {
				++t;
				if(t > n) break;
			}
			if(t > n) break;
			ans2 += a[t].c;
//			cout << a[i]._ << " c " << a[i].c << endl;
			++t;
		}
//		cout << ans2 << endl;
		//__________________________________________________________________________
		for(int i = 1; i <= n; i++) {
			a[i].sa = false;
			a[i].sb = false;
			a[i].sc = false;
		}
		sort(a + 1, a + n + 1, cmp5);
		for(int i = 1; i <= n >> 1; i++) {
			if(a[i].c - max(a[i].a, a[i].b) >= 0) {
				ans3 += a[i].c;
//				cout << a[i]._ << " c " << a[i].c << endl;
				a[i].sc = true;
			} else {
				break;
			}
		}
		sort(a + 1, a + n + 1, cmp6);
		for(int i = 1; i <= n >> 1; i++) {
			if(a[i].sc) break;
			if(a[i].a - a[i].b >= 0) {
				ans3 += a[i].a;
//				cout << a[i]._ << " a " << a[i].a << endl;
				a[i].sa = true;
			} else {
				break;
			}
		}
		t = 1;
		for(int i = 1; i <= n >> 1; i++) {
			while(a[t].sa || a[t].sc) {
				++t;
				if(t > n) break;
			}
			if(t > n) break;
			ans3 += a[t].b;
//			cout << a[i]._ << " b " << a[i].b << endl;
			++t;
		}
//		cout << ans3 << endl;
		cout << max(ans1, max(ans2, ans3)) << endl;
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

*/

