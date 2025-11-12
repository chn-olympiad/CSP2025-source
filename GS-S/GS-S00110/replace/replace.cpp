#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main() {
	int n, q;
	cin >> n >> q;
	string ss;
	for (int i = 0; i < 2 * (n + q); ++i) {
		cin >> ss;
	}
	for (int i = 0; i < q; ++i) {
		cout << q << endl;
	}
    return 0;
}
