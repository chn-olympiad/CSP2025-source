#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[4];
	for(int i = 1; i <= 4; i++) {
		cin >> a[i];
	}
	swap(a[1], a[2]);
	for(int i = 1; i <= 4; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
