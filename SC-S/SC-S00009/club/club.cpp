#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define inf 1e18
using namespace std;
const int maxn = 2e5 + 100;
inline int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if(x < 0) x = -x , putchar('-');
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void writeh(int x) {
	write(x);
	putchar('\n');
}
inline void writek(int x) {
	write(x);
	putchar(' ');
}
int T , n , st[maxn] , vis[maxn];
struct node {
	int a , b , c;
}a[maxn];
inline void work() {
	n = read();
	int cnt1 = 0 , cnt2 = 0 , cnt3 = 0 , ans = 0;
	for(int i = 1; i <= n; ++i) {
		a[i].a = read();
		a[i].b = read();
		a[i].c = read();
		if(a[i].a >= a[i].b && a[i].a >= a[i].c) ans += a[i].a , ++cnt1 , vis[i] = 1;
		else if(a[i].b >= a[i].a && a[i].b >= a[i].c) ans += a[i].b , ++cnt2 , vis[i] = 2;
		else ans += a[i].c , ++cnt3 , vis[i] = 3;
	}
	if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) {
		writeh(ans);
		return ;
	}
	int top = 0;
	if(cnt1 >= n / 2) {
		for(int i = 1; i <= n; ++i) if(vis[i] == 1) st[++top] = a[i].a - max(a[i].b , a[i].c);
		stable_sort(st + 1 , st + 1 + top);
		int o = 1;
		while(cnt1 > n / 2) ans -= st[o] , ++o , --cnt1;
		writeh(ans);
		return ;
	}
	if(cnt2 >= n / 2) {
		for(int i = 1; i <= n; ++i) if(vis[i] == 2) st[++top] = a[i].b - max(a[i].a , a[i].c);
		stable_sort(st + 1 , st + 1 + top);
		int o = 1;
		while(cnt2 > n / 2) ans -= st[o] , ++o , --cnt2;
		writeh(ans);
		return ;
	}
	for(int i = 1; i <= n; ++i) if(vis[i] == 3) st[++top] = a[i].c - max(a[i].a , a[i].b);
	stable_sort(st + 1 , st + 1 + top);
	int o = 1;
	while(cnt3 > n / 2) ans -= st[o] , ++o , --cnt3;
	writeh(ans);
}
signed main() {
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	T = read();
	while(T--) work();
	return 0;
}