#include <bits/stdc++.h>
using namespace std;

int n,m,a[105];

bool cmp(int a,int b) {
	return b < a;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) 
		cin >> a[i];
	int target = a[1],idx;
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= n * m;i++) 
		if (a[i] == target) {
			idx = i;
			break;
		}
	
	int r = idx % n,c;
	if (r == 0) r = n;
	if (idx % n == 0) c = idx / n;
	else c = idx / n + 1;
	if (c % 2 == 0) r = n - r + 1;
	cout << c << ' ' << r << endl;
	return 0;
}
