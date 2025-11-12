#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[116];
bool cmp(int x, int y) {
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int k = n * m;
	int r , x;
	for(int i = 1; i <= k ; i++) {
		cin >> a[i];
		r = a[1];
	}
	sort(a + 1 , a + k + 1 , cmp);
	for(int i = 1; i <= k ; i++) {
		if(a[i] == r) x = i;
	}
	int l = ceil(x * 1.0 / n);
	int h;
	if(l % 2 == 0) {
	    h = n - (x - (l - 1) * n ) + 1;
	}
	else h = x - (l - 1) * n ;
	cout << l << " " << h << endl;
	return 0;
}

