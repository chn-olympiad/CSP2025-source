#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
/*vector<int> arr;

bool cmp (int x, int y) {
	return x < y;
}
*/

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;
	int num = 0;
	for (int i=0; i<s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			arr[num] = s[i] - '0';
			num++;
		}
	}sort(arr, arr + num);
	for (int i=num - 1; i>=0; i--) {
		cout << arr[i];
	}
	fclose(stdin);
	fclose(stdout);
}