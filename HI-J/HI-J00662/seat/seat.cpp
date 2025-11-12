#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, a[110], ms, id, c, r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i=1; i<=n*m; i++) {
		cin >> a[i];
	}
	
	ms = a[1];
	sort(a+1, a+n*m+1);
	
	for (int i=1; i<=n*m; i++) {
		if (a[n*m-i+1] == ms) {
			id = i;
			break;
		}
	}
	cout << id << endl;
	c = (id+n-1)/n;
	r = ((id-1)%n)+1;
	if (c%2==0) {
		r = n-r+1;
	}
	cout << c << ' ' << r;
	
	
	return 0;
}
 
