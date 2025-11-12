#include <bits/stdc++.h>

using namespace std;

const int N = 15;
int c[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string n;
	cin >> n;
	for (int i = 0; i < n.size(); i++) 
		if ('0' <= n[i] and n[i] <= '9') 
			c[n[i] - '0']++;
	for (int i = 9; i >= 0; i--)
		for (int j = 0; j < c[i]; j++)
			cout << i;
	cout << endl;
	return 0;
} 
