#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, m = 3;
struct Node{
	int v, id;
}a[N][4];
int p[N];
int n, T, b[4], mx = 0;
long long ans;
int read() {
	int x = 0, flag = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * flag;
}
void write(int x) {
	if(x < 0) x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
bool cmp1(Node x, Node y) {return x.v > y.v;}
bool cmp2(Node x, Node y) {return x.v < y.v;}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while(T--) {
		ans = 0;
		memset(b, 0, sizeof(b));
		n = read();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				a[i][j].v = read();
				a[i][j].id = j;
			}
			sort(a[i] + 1, a[i] + m + 1, cmp1);
			b[a[i][1].id]++;
			p[i] = a[i][1].v - a[i][2].v;
		//	p[i].id = i;
			ans += a[i][1].v;
		}
		/*for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 4; j++) cout << a[i][j].v << ' ';
			cout << endl;
		}
		for(int i = 1; i <= m; i++) cout << b[i] << ' ';
		cout << endl;*/
		bool pd = 1;
		int w; 
		for(int i = 1; i <= m; i++) {
			if(b[i] > n / 2) {
				mx = b[i];
				pd = 0;
				w = i;
				break;
			}
		}
		//cout << mx << endl;
		//printf("ans: %d\n", ans);
		if(pd == 1) {
			cout << ans << endl;
		}
		else {
			for(int i = 1; i <= n; i++) {
				if(a[i][1].id != w) p[i] = 1e6; 
			}
			sort(p + 1, p + n + 1);
			//for(int i = 1; i <= n; i++) cout << p[i] << ' ';
			//cout << endl;
			for(int i = 1; i <= mx - n / 2; i++) ans -= p[i];
			cout << ans << endl;
		}
	}
	return 0;
}
