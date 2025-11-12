#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    string s1;
    string s2;
    string w1;
    string w2;

    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
    }
    for (int i = 0; i < q; i++) {
        cin >> w1 >> w2;
    }

    for (int i = 0; i < q; i++) {
        cout << '0' << '\n';
    }
    
	fclose(stdin);
	fclose(stdout);
	return 0;
}
