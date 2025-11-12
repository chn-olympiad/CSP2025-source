#include <bits/stdc++.h>
using namespace std;
const int BAD_ALLOC = 2147483647;
int main() {
	for (int i = 1; i <= BAD_ALLOC; i++) {
        auto a = new int[BAD_ALLOC];
        a[BAD_ALLOC-1] = 0;
	}
}

