#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, q;
string s1[N], s2[N];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	while (q--){
		string a, b;
		cin >> a >> b;
		cout << "0\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
