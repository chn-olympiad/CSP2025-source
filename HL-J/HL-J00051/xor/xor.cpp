#include <iostream>
#include <vector>

using namespace std;

int a[500001];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int count = 0;
	int front = 0;
	for (int i = 1; i <= n; i++) {
		bool used = false;
		cin >> a[i];
		if (a[i] == k) {
			front = i;
			count++;
			used = true;
		}
		for (int j = front + 1; j < i; j++) {
			a[j] = a[j] ^ a[i];
			if (a[j] == k && (!used)) {
				front = i;
				count++;
				used = true;
			}
		}
	}
	cout << count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
