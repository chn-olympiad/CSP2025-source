#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m;
string s;
int c[N];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	cout << m;
	return 0;
}
