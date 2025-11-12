#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
int ans1;
int max1 = -1,max2 = -1,max3 = -1;
struct node {
	int a,b,c;
	int q;
} p[100005];
bool cmp1(node x,node y) {
	return min((x.a - x.b),(x.a - x.c)) > min((y.a - y.b),(y.a - y.c));
}
bool cmp2(node x,node y) {
	return min((x.b - x.a),(x.b - x.c)) > min((y.b - y.a),(y.b - y.c));
}
bool cmp3(node x,node y) {
	return min((x.c - x.b),(x.c - x.a)) > min((y.c - y.b),(y.c - y.a));
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t --) {
		ans = 0;
		cin >> n;
		int n2 = n / 2;
		for (int i = 1; i <= n; ++ i) {
			cin >> p[i].a >> p[i].b >> p[i].c;
			p[i].q = 0;
		}
//		for (int i = 1; i <= n; ++ i) cout << p[i].a << " " << p[i].b << " " << p[i].c << "\n";
		int x = 0,y = 0,z = 0;
		sort(p + 1,p + 1 + n,cmp1);
		for (int i = 1; i <= n2; ++ i) {if (p[i].q == 0) ans += p[i].a;p[i].q = 1;}
		sort(p + 1,p + 1 + n,cmp2);
		for (int i = 1; i <= n2; ++ i) {if (p[i].q == 0) ans += p[i].b;p[i].q = 1;}
		sort(p + 1,p + 1 + n,cmp3);
		for (int i = 1; i <= n2; ++ i) {if (p[i].q == 0) ans += p[i].c;p[i].q = 1;}
		cout << ans << "\n";
	}
	return 0;
}
