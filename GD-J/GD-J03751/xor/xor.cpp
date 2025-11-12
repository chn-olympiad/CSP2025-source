#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);

    long long n, k, temp = 0, count = 0, mem = 0;
    cin >> n >> k;
    vector<int> x(n);

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; i++) {
        temp += x[i];
        if (temp == k) {
            count++;
            temp = 0;
        } else if (temp > k) {
            temp = 0;
        }
    }

    cout << count << '\n';
    fclose(stdin);
	fclose(stdout);
    return 0;
}