#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
int count = 0;

int main() {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);  
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort (a + 1, a + 1 + n);

    for (int m = 3; m <= n; ++m) {
        for (int i = 1; i <= n - m + 1; ++i) {
            int sum = 0, large = 0;
            for (int j = i; j < i + m; ++j) {
                sum += a[j];
                if (large < a[j]) large = a[j];
            }
            if (sum > 2 * large) count++;
        }
    }

    cout << count << '\n';
    fclose(stdin);
	fclose(stdout);
    return 0;
}
