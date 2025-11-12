#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string k;
int num;
int a[N];
int cmp(int x, int y) {
	return x > y;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("number.in","r", stdin);
	freopen("number.out","w", stdout);
	cin >> k;
	int n = k.size();
	for(int i = 0; i < n; i++) {
		if(k[i] <= '9' && k[i] >= '0') {
			num++;
			a[num] = k[i] - '0';
		}
	}sort(a + 1,a + 1 + num, cmp);
	for(int i = 1; i <= num; i++){
		cout << a[i];
	}return 0;
}
