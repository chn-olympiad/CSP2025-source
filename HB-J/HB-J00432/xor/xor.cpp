#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
struct pos {
	int left;
	int right;
};
int a[500001];
vector<pos> v;

int sum_xor(int l, int r) {
	int sum = a[l];
	for (int i = l + 1; i <= r; i++)
		sum ^= a[i];
	return sum;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++)
			if (sum_xor(l, r) == k)
				v.push_back({l, r});
	cout << v.size();
	return 0;
}
