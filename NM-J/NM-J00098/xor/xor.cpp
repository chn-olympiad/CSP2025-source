#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int a[MAXN];

int main() {
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    int n;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cnt++;
		}else if (a[i] == a[i+1]) {
			cnt++;
			i++;
		}
	}
	cout << cnt;
    return  0;
}


