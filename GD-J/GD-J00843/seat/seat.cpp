#include <iostream>
#include <algorithm>
using namespace std;
const int N = 505;
int n, m, a[N], s, k = 1;
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	s = a[1];
	for(int i = 1; i <= n * m; i++){
		if(a[i] > s) k++;
	}
	int j = (k - 1) / n + 1;
	int i = k % n;
	if(i == 0) i = n;
	if(j % 2 == 0) i = n - i + 1;
	cout << j << " " << i << endl;
	return 0;
}

