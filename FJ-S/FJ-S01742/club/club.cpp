#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Max = 2e5 + 9;
struct Node {
	int a,b,c,s;
} mem[Max];
int t,n,a,b,c,ans;
Node aa[Max],bb[Max],cc[Max];
bool cmp(Node x,Node y) {
	return x.s <= y.s;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--) {
		for(int i = 1;i <= n;i++) {
			mem[i] = {0,0,0,0},aa[i] = {0,0,0,0};
			bb[i] = {0,0,0,0},cc[i] = {0,0,0,0};
		}
		a = 0,b = 0,c = 0,ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++) {
			cin >> mem[i].a >> mem[i].b >> mem[i].c;
			if(mem[i].a >= mem[i].b && mem[i].a >= mem[i].c) {
				a++,ans += mem[i].a;
				if(mem[i].b >= mem[i].c) mem[i].s = mem[i].a - mem[i].b;
				else mem[i].s = mem[i].a - mem[i].c;
				aa[a] = mem[i];
			}
			else if(mem[i].b >= mem[i].a && mem[i].b >= mem[i].c) {
				b++,ans += mem[i].b;
				if(mem[i].a >= mem[i].c) mem[i].s = mem[i].b - mem[i].a;
				else mem[i].s = mem[i].b - mem[i].c;
				bb[b] = mem[i];
			}
			else {
				c++,ans += mem[i].c;
				if(mem[i].a >= mem[i].b) mem[i].s = mem[i].c - mem[i].a;
				else mem[i].s = mem[i].c - mem[i].b;
				cc[c] = mem[i];
			}
		}
//		cout << a << " " << b << " " << c << "\n";
		if (a > (n / 2)) {
//			cout << "a\n";
			sort(aa + 1,aa + a + 1,cmp);
			for(int i = 1;i <= a - (n / 2);i++) ans -= aa[i].s;
		}
		if (b > (n / 2)) {
//			cout << "b\n";
			sort(bb + 1,bb + b + 1,cmp);
			for(int i = 1;i <= b - (n / 2);i++) ans -= bb[i].s;
		}
		if (c > (n / 2)) {
//			cout << "c\n";
			sort(cc + 1,cc + c + 1,cmp);
			for(int i = 1;i <= c - (n / 2);i++) ans -= cc[i].s;
		}
		cout << ans << "\n";
	}
	return 0;
}
