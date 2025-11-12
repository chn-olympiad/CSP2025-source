#include <bits/stdc++.h>
using namespace std;
/*
struct stu {
	struct node {
		int no, val;
	};
	
	node a[3];
	int nn = -1, nv;
};
*/
int read() {
	int x = 0;
	bool neg = false;
	char ch = 0;
	
	while (ch < '0' || ch > '9') {
		if (ch == '-') neg = true;
		ch = getchar();
	}

	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	
	return neg ? -x : x;
}

void write(int x) {
	bool neg = false;
	if (x < 0) {
		putchar('-');
		neg = true;
	}
	
	static int sta[48];
	int top = 0;
	
	do {
		sta[top++] = x % 10;
		x /= 10;
	} while (x);
	
	if (neg) while(top) putchar('0' - sta[--top]);
	else while(top) putchar('0' + sta[--top]);
	
	return ;
}
/*
auto cmp = [](stu x, stu y) {
	return x.nv < y.nv;
};
priority_queue<stu, vector<stu>, decltype(cmp)> a;
*/
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while (T--) {
		int n = read();
		int ans = 0; 
		for (int i = 0; i < n; i++) {
			int t = read(), t2 = read(), t3 = read();
			ans += t;
		}
		
		write(ans);
		/*stu ss;
		for (int i = 1; i <= n; i++) {
			int t1 = read(), t2 = read(), t3 = read();
			if (t1 >= t2 && t2 >= t3) {
				ss.a[0].no = 1, ss.a[0].no = t1;
				ss.a[1].no = 2, ss.a[1].no = t2;
				ss.a[2].no = 3, ss.a[2].no = t3;
				ss.nn = 1, ss.nv = t1;
				a.push(ss);
			} else if (t1 >= t3 && t3 >= t2) {
				ss.a[0].no = 1, ss.a[0].no = t1;
				ss.a[1].no = 3, ss.a[1].no = t3;
				ss.a[2].no = 2, ss.a[2].no = t2;
				ss.nn = 1, ss.nv = t1;
				a.push(ss);
			} else if (t2 >= t1 && t1 >= t3) {
				ss.a[0].no = 2, ss.a[0].no = t2;
				ss.a[1].no = 1, ss.a[1].no = t1;
				ss.a[2].no = 3, ss.a[2].no = t3;
				ss.nn = 1, ss.nv = t2;
				b.push(ss);
			} else if (t2 >= t3 && t3 >= t1) {
				ss.a[0].no = 2, ss.a[0].no = t2;
				ss.a[1].no = 3, ss.a[1].no = t3;
				ss.a[2].no = 1, ss.a[2].no = t1;
				ss.nn = 1, ss.nv = t2;
				b.push(ss);
			} else if (t3 >= t1 && t1 >= t2) {
				ss.a[0].no = 3, ss.a[0].no = t3;
				ss.a[1].no = 1, ss.a[1].no = t1;
				ss.a[2].no = 2, ss.a[2].no = t2;
				ss.nn = 1, ss.nv = t3;
				c.push(ss);
			} else if (t3 >= t2 && t2 >= t1) {
				ss.a[0].no = 3, ss.a[0].no = t3;
				ss.a[1].no = 2, ss.a[1].no = t2;
				ss.a[2].no = 1, ss.a[2].no = t1;
				ss.nn = 1, ss.nv = t3;
				c.push(ss);
			}
		}
		
		int ans = 0;
		while (a.size() > n / 2 || b.size() > n / 2 || c.size() > n / 2) {
			while (a.size() > n / 2) {
				stu u = a.top();
				a.pop();
				while (u.nn == 3) {
					ans += u.nv;
					u = a.top();
					a.pop();
				}
				
				if (u.nn == 1) {
					u.nn = 2;
					u.nv = u.a[1].val;
					if (u.a[1].no == 2) b.push(u);
					else if(u.a[1].no == 3) c.push(u);
				} else if (u.nn == 2) {
					u.nn = 3;
					u.nv = u.a[2].val;
					if (u.a[2].no == 2) b.push(u);
					else if(u.a[2].no == 3) c.push(u);
				}
			}
			
			while (b.size() > n / 2) {
				stu u = b.top();
				b.pop();
				while (u.nn == 3) {
					ans += u.nv;
					u = b.top();
					b.pop();
				}
				
				if (u.nn == 1) {
					u.nn = 2;
					u.nv = u.a[1].val;
					if (u.a[1].no == 1) a.push(u);
					else if(u.a[1].no == 3) c.push(u);
				} else if (u.nn == 2) {
					u.nn = 3;
					u.nv = u.a[2].val;
					if (u.a[2].no == 1) a.push(u);
					else if(u.a[2].no == 3) c.push(u);
				}
			}
			
			while (c.size() > n / 2) {
				stu u = c.top();
				c.pop();
				while (u.nn == 3) {
					ans += u.nv;
					u = c.top();
					c.pop();
				}
				
				if (u.nn == 1) {
					u.nn = 2;
					u.nv = u.a[1].val;
					if (u.a[1].no == 2) b.push(u);
					else if(u.a[1].no == 1) a.push(u);
				} else if (u.nn == 2) {
					u.nn = 3;
					u.nv = u.a[2].val;
					if (u.a[2].no == 2) b.push(u);
					else if(u.a[2].no == 1) a.push(u);
				}
			}
		}
		
		while (!a.empty()) {
			ans += a.top().nv;
			a.pop();
		}
		while (!b.empty()) {
			ans += b.top().nv;
			b.pop();
		}
		while (!c.empty()) {
			ans += c.top().nv;
			c.pop();
		}
		
		write(ans);
		putchar('\n');*/
	}
}
