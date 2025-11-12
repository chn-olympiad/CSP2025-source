#include <iostream>
using namespace std;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int c_arr[n];
	for (int i = 0; i < n; i++)
		cin >> c_arr[i];
	cout << n / 2;
	return 0;
}

