#include <iostream>
#include <cmath>
using namespace std;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string s[n], t[q];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < q; i++)
		cin >> t[i];
	for (int i = 0; i < q; i++)
		cout << abs(n - q) << '\n' << abs(n - pow(q, 2));
	return 0;
}

