//GZ-S00166 + 贵州省遵义市南白中学 + 张泽文 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10;

ll read() {int f = 1;char ch;ll x = 0;ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-') f = -1;ch = getchar();}while (ch >= '0' && ch <= '9') {x = x * 10 + (ch - '0');ch = getchar();}return x * f;}

void write(ll x) {if (x < 0) {putchar('-');x = -x;}if (x > 9) write(x / 10);putchar(x % 10 + '0');}

struct eee {
	int a, b, c;
	int sum;
}man[MAXN];

bool cmp(eee a, eee b) {
	return a.sum > b.sum;
}

int T;
int n;
bool ok[3];
int cnt[3];
ll ans;

int firstt(int a, int b, int c) {
	if (a > b && a > c)
		return a;
	if (b > a && b > c)
		return b;
	if (c > a && c > b)
		return c;		
}

void init() {
	ans = 0;
	ok[0] = false; ok[1] = false; ok[2] = false;
	cnt[0] = 0; cnt[1] = 0; cnt[2] = 0;
}

void work() {
	n = read();
	init();
	
	for (int i = 1; i <= n; ++ i) {
		man[i].a = read();
		man[i].b = read();
		man[i].c = read();
		man[i].sum = man[i].a + man[i].b + man[i].c;
	}
	
	int maxn = n >> 1;
	sort(man + 1, man + n + 1, cmp);
	
	for (int i = 1; i <= n; ++ i) {
		int temp = firstt(man[i].a, man[i].b, man[i].c);
		if (temp == man[i].a && !ok[0]) {
			if (cnt[0] + 1 < maxn) {
				ans += temp;
				++ cnt[0];
			}
			else {
				temp = firstt(man[i].a, man[i + 1].a + man[i].b, man[i + 1].a + man[i].c);
				if (temp == man[i].a) {ans += man[i].a;cnt[0] ++;ok[0] = true;continue;}
				else if (temp == man[i + 1].a + man[i].b) {ans += man[i].b;cnt[1] ++;continue;}
				else {ans += man[i].c;cnt[2] ++;continue;}	
			}
		}
		if (temp == man[i].b && !ok[1]) {
			if (cnt[1] + 1 < maxn) {
				ans += temp;
				++ cnt[1];
			}
			else {
				temp = firstt(man[i].b, man[i + 1].b + man[i].a, man[i + 1].b + man[i].c);
				if (temp == man[i].b) {ans += man[i].b;cnt[1] ++;ok[1] = true;continue;}
				else if (temp == man[i + 1].b + man[i].a) {ans += man[i].a;cnt[0] ++;continue;}
				else {ans += man[i].c;cnt[2] ++;continue;}
			}	
		}
		if (temp == man[i].c && !ok[2]) {
			if (cnt[2] + 1 < maxn) {
				ans += temp;
				++ cnt[2];
			}
			else {
				temp = firstt(man[i].c, man[i + 1].c + man[i].a, man[i + 1].c + man[i].b);
				if (temp == man[i].c) {ans += man[i].c;cnt[2] ++;ok[2] = true;continue;}
				else if (temp == man[i + 1].c + man[i].a) {ans += man[i].a;cnt[0] ++;continue;}
				else {ans += man[i].b;cnt[1] ++;continue;}
			}
		}
	}
	write(ans);
	putchar('\n');
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while(T --)
		work();
	return 0;
}
