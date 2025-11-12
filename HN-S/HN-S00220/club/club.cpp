#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
struct node{
	int a, b, c;
}s[N];
int n, T;
int ans;
bool cmp(node A,node B) {
	return max(A.b, A.c) - A.a > max(B.b,B.c) - B.a;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T --) {
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			cin>> s[i].a >> s[i].b >> s[i].c;
			ans += s[i].a;
		}
		sort(s + 1, s + n + 1, cmp);
		int lenb = 0;
		int lenc = 0;
		for(int i = 1;i <= n / 2;i ++) {
			if(s[i].b > s[i].c) {
				if(lenb + 1 <= n / 2) {
					lenb ++;
					ans += s[i].b - s[i].a;
				} else {
					lenc ++;
					ans += s[i].c - s[i].a;
				}
			} else {
				if(lenc + 1 <= n / 2) {
					lenc ++;
					ans += s[i].c - s[i].a;
				} else {
					lenb ++;
					ans += s[i].b - s[i].a;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

