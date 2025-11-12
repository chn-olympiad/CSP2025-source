#include<iostream>
#include<algorithm>
using namespace std;
const int N = 15;
int n,m;
int a[N],a1;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	a1 = a[1];
	sort(a + 1,a + 1 + n * m,greater<int>());
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == a1) {
			//cout << "i = " << i << "\n";
			int x,y;
			y = (i + n - 1) / n;
			if (y & 1) {
				x = (i - 1) % n + 1;
			}
			else {
				x = n - (i - 1) % n;
			}
			cout << y << " " << x;
			break;
		}
	}
	return 0;
}
