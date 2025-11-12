#include <iostream>
#define maxn 15
using namespace std;
string str;
int a[maxn];
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	for (auto it : str)
		if (isdigit(it)) a[it - 48]++;
	for (int i = 9; i >= 0; i--)
		for (int j = 1; j <= a[i]; j++) cout << i;
	cout << endl;
	return 0;
}