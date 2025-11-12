#include<iostream>
#include<queue>
#include<vector>
using namespace std;
string s;
int num[20];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> s;
	for (int i = 0; i < (int)(s.size()); i++) num[s[i] - '0']++;
	for (int i = 9; ~i; i--) while (num[i]--) cout << i;
	return 0;
}
//OK 100pts
