#include <iostream>
#include <algorithm>
using namespace std;
int a[10005];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, sizea, t, pai;
	cin >> n >> m;
	sizea = n * m;
	for (int i = 1; i <= sizea; i++){
		cin >> a[i]; 
	}
	t = a[1];
	sort(a + 1, a + sizea + 1, cmp);
	for (int i = 1; i <= sizea; i++){
		if (a[i] == t){
			pai = i;
			break;
		}
	}
	int c, r;
	double z;
	z = (double)pai / (double)n;
	c = ceil(z);
	r = pai % n;
	if (r == 0) r = n;
	if (c % 2 == 0) r = n - r + 1;
	cout << c << " " << r;
	//for (int i = 1; i <= sizea; i++) cout << a[i] << " ";
	return 0;
}
