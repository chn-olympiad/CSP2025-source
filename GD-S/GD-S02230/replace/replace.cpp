#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const int inf = 2e9;

struct node {
	int l, r, lx, rx;
} a[N];

char ch;
int cinl, cinr;
void read_str() {
	cinl = cinr = 0;
	while (ch=getchar(), ch<'a'||ch>'z');
	while (ch >= 'a' && ch <= 'z') {
		if (ch == 'b') break;
		cinl++;
		ch = getchar();
	}
	while (ch=getchar(), ch>='a'&&ch<='z') {
		cinr++;
	}
}

int n, q, l1, l2, r1, r2;
ll ans;

void gt2() {
	read_str(); l1 = cinl; r1 = cinr;
	read_str(); l2 = cinl; r2 = cinr;
//	printf("readed: %d %d\n", l2 - l1, r2 - r1);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		gt2();
		a[i].l = l2 - l1;
		a[i].r = r2 - r1;
		a[i].lx = l1;
		a[i].rx = r1;
	}
	for (int i = 1; i <= q; i++) {
		gt2();
		ans = 0;
		l2 = l2 - l1;
		r2 = r2 - r1;
		for (int j = 1; j <= n; j++) {
//			printf("comp %d: %d %d - %d %d\n", j, l1, r1, a[i].l, a[i].r);
			if (l1 >= a[j].lx && r1 >= a[j].rx && l2 == a[j].l && r2 == a[j].r) ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
4 6
ab aba
ba aba
aba aba
aabaa aabaa
aba abaa
baa abaa
aaba aabaa
aaba aaaba
aabaa aabaa
aba aba
*/

