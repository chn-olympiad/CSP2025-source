#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct node {
	int x, y, z, xb;
}a[N * 3];

int t1, t2, t3;
int x1[N], y2[N], z3[N]; 

int zh[N], t;

int cmp_x (node a, node b) {
	return a.x < b.x;
}

int cmp_y (node a, node b) {
	return a.y < b.y;
}

int cmp_z (node a, node b) {
	return a.z < b.z;
}

int cmp_xb (node a, node b) {
	return a.xb < b.xb;
}

void solve () {
	int n;
	cin >> n;
	
	memset (x1, 0, sizeof (x1));
	memset (y2, 0, sizeof (y2));
	memset (z3, 0, sizeof (z3));
	t1 = 0, t2 = 0, t3 = 0;
	
	int bz = n / 2;
	
	bool f = false, f1 = false, f2 = false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		
		a[i].xb = i;
		
		if (a[i].y == 0 && a[i].z == 0) f = true; 
		if (a[i].x == 0 && a[i].z == 0) f1 = true;
		if (a[i].x == 0 && a[i].y == 0) f2 = true; 
	}
	
	if (!f && !f1 && !f2) {
		for (int i = 1; i <= n; i++) {
		
		//一个活着的 
		if (t1 == bz && t2 == bz && t3 < bz) {
			z3[++t3] = a[i].z;
			
			continue;
		} 
		if (t1 == bz && t2 < bz && t3 == bz) {
			y2[++t2] = a[i].y; 
			
			continue;
		}
		if (t1 < bz && t2 == bz && t3 == bz) {
			x1[++t1] = a[i].x;
			
			continue;
		}
		
		// 两个活着的 
		if (t1 == bz && t2 < bz && t3 < bz) {
			if (t2 == bz) z3[++t3] = a[i].z;
			if (t3 == bz) y2[++t2] = a[i].y; 
			
			if (a[i].y > a[i].z && t2 < bz) y2[++t2] = a[i].y; 
			if (a[i].z > a[i].y && t3 < bz) z3[++t3] = a[i].z;
			
			continue;
		} 
		if (t2 == bz && t1 < bz && t3 < bz) {
			if (t1 == bz) z3[++t3] = a[i].z;
			if (t3 == bz) x1[++t1] = a[i].x;
			
			if (a[i].x > a[i].z && t1 < bz) x1[++t1] = a[i].x;
			if (a[i].z > a[i].x && t3 < bz) z3[++t3] = a[i].z;
			
			continue;
		}
		if (t3 == bz && t2 < bz && t1 < bz) {
			if (t2 == bz) z3[++t3] = a[i].z;
			if (t1 == bz) y2[++t2] = a[i].y; 
			
			if (a[i].x > a[i].y && t1 < bz) x1[++t1] = a[i].x;
			if (a[i].y > a[i].x && t2 < bz) y2[++t2] = a[i].y;
			
			continue;
		}
		
		//三个活着的 
		if (a[i].x > a[i].y && a[i].x > a[i].z && t1 < bz) x1[++t1] = a[i].x;
		if (a[i].y > a[i].x && a[i].y > a[i].z && t2 < bz) y2[++t2] = a[i].y; 
		if (a[i].z > a[i].x && a[i].z > a[i].y && t3 < bz) z3[++t3] = a[i].z;
	}
	int ans = 0;
	
	for (int i = 1; i <= t1; i++) ans += x1[i];
	for (int i = 1; i <= t2; i++) ans += y2[i];
	for (int i = 1; i <= t3; i++) ans += z3[i];
	
	zh[++t] = ans;
	
	return;
	}
		
	if (f && !f1 && !f2) {
		for (int i = 1; i <= n; i++) {
			sort (a + 1, a + n + 1, cmp_x);
			
			if (a[i].x > a[i].y && a[i].x > a[i].z && t1 < bz) {
				x1[++t1] = a[i].x;
				
				continue;
			}
			if (t1 < bz && t2 == bz && t3 == bz) {
				x1[++t1] = a[i].x;
				
				continue;
			}
			if (t2 == bz && t1 < bz && t3 < bz) {
				if (t1 == bz) z3[++t3] = a[i].z;
				if (t3 == bz) x1[++t1] = a[i].x;
				
				if (a[i].x > a[i].z && t1 < bz) x1[++t1] = a[i].x;
				if (a[i].z > a[i].x && t3 < bz) z3[++t3] = a[i].z;
				
				continue;
			}
			if (t3 == bz && t2 < bz && t1 < bz) {
				if (t2 == bz) z3[++t3] = a[i].z;
				if (t1 == bz) y2[++t2] = a[i].y; 
				
				if (a[i].x > a[i].y && t1 < bz) x1[++t1] = a[i].x;
				if (a[i].y > a[i].x && t2 < bz) y2[++t2] = a[i].y;
				
				continue;
			}
			
			sort (a + 1, a + n + 1, cmp_y);
			
			if (a[i].y > a[i].x && a[i].y > a[i].z && t2 < bz) {
				y2[++t2] = a[i].y;
				
				continue;
			}
			if (t1 == bz && t2 == bz && t3 < bz) {
				z3[++t3] = a[i].z;
				
				continue;
			}
			if (t1 == bz && t2 < bz && t3 < bz) {
				if (t2 == bz) z3[++t3] = a[i].z;
				if (t3 == bz) y2[++t2] = a[i].y; 
				
				if (a[i].y > a[i].z && t2 < bz) y2[++t2] = a[i].y; 
				if (a[i].z > a[i].y && t3 < bz) z3[++t3] = a[i].z;
				
				continue;
			}
			if (t3 == bz && t2 < bz && t1 < bz) {
				if (t2 == bz) z3[++t3] = a[i].z;
				if (t1 == bz) y2[++t2] = a[i].y; 
				
				if (a[i].x > a[i].y && t1 < bz) x1[++t1] = a[i].x;
				if (a[i].y > a[i].x && t2 < bz) y2[++t2] = a[i].y;
				
				continue;
			}
			
			sort (a + 1, a + n + 1, cmp_z);
			
			if (a[i].z > a[i].x && a[i].z > a[i].y && t3 < bz) {
				z3[++t3] = a[i].z;
				
				continue;
			}
			if (t1 == bz && t2 == bz && t3 < bz) {
				z3[++t3] = a[i].z;
				
				continue;
			} 
			if (t1 == bz && t2 < bz && t3 < bz) {
				if (t2 == bz) z3[++t3] = a[i].z;
				if (t3 == bz) y2[++t2] = a[i].y; 
				
				if (a[i].y > a[i].z && t2 < bz) y2[++t2] = a[i].y; 
				if (a[i].z > a[i].y && t3 < bz) z3[++t3] = a[i].z;
				
				continue;
			} 
			if (t2 == bz && t1 < bz && t3 < bz) {
				if (t1 == bz) z3[++t3] = a[i].z;
				if (t3 == bz) x1[++t1] = a[i].x;
					
				if (a[i].x > a[i].z && t1 < bz) x1[++t1] = a[i].x;
				if (a[i].z > a[i].x && t3 < bz) z3[++t3] = a[i].z;	
				
				continue;
			}
			
			sort (a + 1, a + n + 1, cmp_xb);
		}
		
		int ans = 0;
		
		for (int i = 1; i <= t1; i++) ans += x1[i];
		for (int i = 1; i <= t2; i++) ans += y2[i];
		for (int i = 1; i <= t3; i++) ans += z3[i];
		
		zh[++t] = ans;
		
		return;
	}
	
	if (f1 && !f2) {
		sort (a + 1, a + n + 1, cmp_y);
		
//		for (int i = 1; i <= n; i++) cout << a[i].y << " ";
//		cout << '\n';
		
		for (int i = n; i >= 1; i--) {
			if (t2 == bz) break;
			
			y2[++t2] = a[i].y;
		}
		
		
	int ans = 0;
	
	for (int i = 1; i <= t2; i++) ans += y2[i];
	
	zh[++t] = ans;
	
	return;
	}
	
	
	if (f2) {
		for (int i = 1; i <= n; i++) {
			sort (a + 1, a + n + 1, cmp_x);
			
			if (a[i].x > a[i].y && a[i].x > a[i].z && t1 < bz) {
				x1[++t1] = a[i].x;
				
				continue;
			}
			if (t1 < bz && t2 == bz && t3 == bz) {
				x1[++t1] = a[i].x;
				
				continue;
			}
			if (t2 == bz && t1 < bz && t3 < bz) {
				if (t1 == bz) z3[++t3] = a[i].z;
				if (t3 == bz) x1[++t1] = a[i].x;
				
				if (a[i].x > a[i].z && t1 < bz) x1[++t1] = a[i].x;
				if (a[i].z > a[i].x && t3 < bz) z3[++t3] = a[i].z;
				
				continue;
			}
			if (t3 == bz && t2 < bz && t1 < bz) {
				if (t2 == bz) z3[++t3] = a[i].z;
				if (t1 == bz) y2[++t2] = a[i].y; 
				
				if (a[i].x > a[i].y && t1 < bz) x1[++t1] = a[i].x;
				if (a[i].y > a[i].x && t2 < bz) y2[++t2] = a[i].y;
				
				continue;
			}
			
			sort (a + 1, a + n + 1, cmp_y);
			
			if (a[i].y > a[i].x && a[i].y > a[i].z && t2 < bz) {
				y2[++t2] = a[i].y;
				
				continue;
			}
			if (t1 == bz && t2 == bz && t3 < bz) {
				z3[++t3] = a[i].z;
				
				continue;
			}
			if (t1 == bz && t2 < bz && t3 < bz) {
				if (t2 == bz) z3[++t3] = a[i].z;
				if (t3 == bz) y2[++t2] = a[i].y; 
				
				if (a[i].y > a[i].z && t2 < bz) y2[++t2] = a[i].y; 
				if (a[i].z > a[i].y && t3 < bz) z3[++t3] = a[i].z;
				
				continue;
			}
			if (t3 == bz && t2 < bz && t1 < bz) {
				if (t2 == bz) z3[++t3] = a[i].z;
				if (t1 == bz) y2[++t2] = a[i].y; 
				
				if (a[i].x > a[i].y && t1 < bz) x1[++t1] = a[i].x;
				if (a[i].y > a[i].x && t2 < bz) y2[++t2] = a[i].y;
				
				continue;
			}
			
			sort (a + 1, a + n + 1, cmp_z);
			
			if (a[i].z > a[i].x && a[i].z > a[i].y && t3 < bz) {
				z3[++t3] = a[i].z;
				
				continue;
			}
			if (t1 == bz && t2 == bz && t3 < bz) {
				z3[++t3] = a[i].z;
				
				continue;
			} 
			if (t1 == bz && t2 < bz && t3 < bz) {
				if (t2 == bz) z3[++t3] = a[i].z;
				if (t3 == bz) y2[++t2] = a[i].y; 
				
				if (a[i].y > a[i].z && t2 < bz) y2[++t2] = a[i].y; 
				if (a[i].z > a[i].y && t3 < bz) z3[++t3] = a[i].z;
				
				continue;
			} 
			if (t2 == bz && t1 < bz && t3 < bz) {
				if (t1 == bz) z3[++t3] = a[i].z;
				if (t3 == bz) x1[++t1] = a[i].x;
					
				if (a[i].x > a[i].z && t1 < bz) x1[++t1] = a[i].x;
				if (a[i].z > a[i].x && t3 < bz) z3[++t3] = a[i].z;	
				
				continue;
			}
			
			sort (a + 1, a + n + 1, cmp_xb);
		}
	}
	
	int ans = 0;
		
		for (int i = 1; i <= t1; i++) ans += x1[i];
		for (int i = 1; i <= t2; i++) ans += y2[i];
		for (int i = 1; i <= t3; i++) ans += z3[i];
		
		zh[++t] = ans;	
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	int T;
	
	cin >> T;
	
	while (T--) solve ();
	
	for (int i = 1; i <= t; i++) cout << zh[i] << endl;
	
	return 0;
} 

/**
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
**/
