#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 150;
int a[N];
int x;
int rsid;
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    int number = n * m;
    for(int i=1;i<=number;i++) {
    	cin >> a[i];
	}
	x = a[1];
	sort(a + 1,a + number + 1,greater<int>());
	for(int i=1;i<=number;i++) {
		if(a[i] == x) {
			rsid = i;
		}
	}
	int r = rsid / n;
	if(rsid % n != 0) {
		r ++;
	}
	int c = rsid % n;
	if(c == 0) {
		c = n;
	}
	if(r % 2 == 1) {
		c = c;
	}else {
		c = n - c + 1;
	}
	cout << r << " " << c;
	return 0;
}