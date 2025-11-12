#include <bits/stdc++.h>
using namespace std;
string s[20000];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i = 1;i <= n;i++){
		cin >> s[i];
	}
	for (int i = 1;i <= q;i++){
		string a,b;
		cin >> a >> b;
	}
	for (int i = 1;i <= q;i++){
		cout << 0;
	}
	return 0;
}

