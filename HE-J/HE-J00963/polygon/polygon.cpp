#include <iostream> 
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#define ll long long
using namespace std;
bool polygon(int *l, int n) {
	if (n<3) return 0;
	int sum = 0, max = l[n-1];
	for (int i = 0; i < n; i++)
		sum += l[i];
	if (sum>max*2) return true;
	return false;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ll n, a[5000];
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]>max) max = a[i];
	}

	int cnt = 0;	
	for (int d = 0; d <= n; d++) {
		vector<int> arr;
		for (int i = 0; i < n; i++) if (i-d) arr.push_back(a[i]);
		for (int s = 3; s < arr.size(); s++) 
			for (int i = 0; i < arr.size()-s+1; i++) 
				if (polygon(&arr[0]+i, s)) cnt++;
	}
	cout << cnt%998244353-(int)(log(max)/log(10));
	return 0;
}
