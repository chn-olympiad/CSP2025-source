#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int R, n, m, a[105], c, r;
int main(){
	freopen("seat3.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n * m; i++){
		cin >> a[i];
	}
	R = a[0];
	a[n * m] = 105;
	sort(a + 1, a + n * m, greater<int>());
	if(R > a[1]){
		cout << m << " " << n;
		return 0;
	}
	if(R < a[n * m - 1]){
		cout << "1 1";
		return 0;
	}	
	for(int i = 1; i < n * m; i++){
		if(a[i] > R && a[i + 1] < R){
			int t = i + 1;
			c = t / n;
			r = t % n;
			if(t % n != 0) c++;
			if(c % 2 == 0){
				r = n - r + 1;
			}
			if(t % n == 0) r = n;
			break;
		}
	}
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
