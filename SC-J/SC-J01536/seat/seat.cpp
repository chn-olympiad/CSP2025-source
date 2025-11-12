#include <bits/stdc++.h>

#define N ((int)1e3 + 10)

using namespace std;

int n, m;

struct stu {
	int w;
	bool is_1;
	
	inline bool operator < (const stu &s2) const {
		return w > s2.w;
	}
}a[N];

int main() {
#ifdef XYX
//	freopen("seat3.in", "r", stdin);
//	freopen("seat3.out", "w", stdout);
#else 
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) {
		cin >> a[i].w;
		a[i].is_1 = (i == 1) ? 1 : 0; 
	}
	
	sort(a + 1, a + n * m + 1);
#ifdef XYX
	for(int i = 1;i <= n * m;i++) {
		cout << a[i].w << "," << a[i].is_1 << " ";
	}
	cout << endl; 
#endif
	
	int i = 0;
	for(int r = 1;r <= m;r++) {
		if(r % 2 == 1) {
			for(int c = 1;c <= n;c++) {
#ifdef XYX
//				cout << r << " " << c << " " << i << endl;
#endif
				++i;
				if(a[i].is_1) {
					cout << r << " " << c;
				} 
			}
		}
		else {
			for(int c = n;c >= 1;c--) {
#ifdef XYX
//				cout << r << " " << c << " " << i << endl;
#endif
				++i;
				if(a[i].is_1) {
					cout << r << " " << c;
				} 
			}
		}
	} 
	
	return 0;
}

/*
3 2
3 1 2 4 6 5

2 3
3 1 2 4 6 5
*/