#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
//#define int long long
//#define int unsigned long long
/*
T4 of 12 ~ 24 pts ended at 11:29
*/
using namespace std;
const int N = 1e6;
int n,a[N],ans;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n <= 3) {
		if(n <= 2) {
			cout << 0;
			return 0;
		}else {
			if(a[1] + a[2] + a[3] > 2*max(a[1],max(a[2],a[3]))) {
				cout << 1;
				return 0;
			}else {
				cout << 0;
				return 0;
			}
		}
	}else {
		for(int x = 1; x <= n; x++)
			for(int b = 1; b <= x; b++)
				for(int c = 1; c <= b; c++)
					if(x != b && b != c && x != c)
						if(a[x] + a[b] + a[c] > 2*max(a[x],max(a[b],a[c]))) ans++;
		for(int x = 1; x <= n; x++)
			for(int y = 1; y <= x; y++)
				for(int z = 1; z <= y; z++)
					for(int w = 1; w <= z; w++)
						if(x != y && x != z && x != w && y != z && y != w && z != w)
							if(a[x] + a[y] + a[z] + a[w] > 2*max(max(a[x],a[y]),max(a[z],a[w]))) ans++;
		for(int a1 = 1; a1 <= n; a1++)
			for(int a2 = 1; a2 <= a1; a2++)
				for(int a3 = 1; a3 <= a2; a3++)
					for(int a4 = 1; a4 <= a3; a4++)
						for(int a5 = 1; a5 <= a4; a5++)
							if(a1 != a2 && a1 != a3 && a1 != a4 && a1 != a5 && a2 != a3 && a2 != a4 && a2 != a5 && a3 != a4 && a3 != a5 && a4 != a5)
								if(a[a1] + a[a2] + a[a3] + a[a4] + a[a5] > 2*max(max(a[a1],max(a[a2],a[a3])),max(a[a4],a[a5]))) ans++;
		for(int b1 = 1; b1 <= n; b1++)
			for(int b2 = 1; b2 <= b1; b2++)
				for(int b3 = 1; b3 <= b2; b3++)
					for(int b4 = 1; b4 <= b3; b4++)
						for(int b5 = 1; b5 <= b4; b5++)
							for(int b6 = 1; b6 <= b5; b6++)
								if(b1 != b2 && b1 != b3 && b1 != b4 && b1 != b5 && b1 != b6 && b2 != b3 && b2 != b4 && b2 != b5 && b2 != b6 && b3 != b4 && b3 != b5 && b3 != b6 && b4 != b5 && b4 != b6 && b5 != b6)
									if(a[b1]+a[b2]+a[b3]+a[b4]+a[b5]+a[b6] > max(max(a[b1],a[b2]),max(a[b3],a[b4]),max(a[b5]),a[b6])) ans++;
		for(int b1 = 1; b1 <= n; b1++)
			for(int b2 = 1; b2 <= b1; b2++)
				for(int b3 = 1; b3 <= b2; b3++)
					for(int b4 = 1; b4 <= b3; b4++)
						for(int b5 = 1; b5 <= b4; b5++)
							for(int b6 = 1; b6 <= b5; b6++)
								for(int b7 = 1; b7 <= b6; b7++)
									if(b1 != b2 && b1 != b3 && b1 != b4 && b1 != b5 && b1 != b6 && b1 != b7 && b2 != b3 && b2 != b4 && b2 != b5 && b2 != b6 && b2 != b7 && b3 != b4 && b3 != b5 && b3 != b6 && b3 != b7 && b4 != b5 && b4 != b6 && b4 != b7 && b5 != b6 && b5 != b7 && b6 != b7)
										if(a[b1]+a[b2]+a[b3]+a[b4]+a[b5]+a[b6]+a[b7] > max(max(max(a[b1],a[b2]),max(a[b3],a[b4]),max(a[b5]),a[b6]),b[7])) ans++;
		cout << ans;
	}
	return 0;
}

