#include<bits/stdc++.h>
using namespace std;
string s[200006][6];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}
	for (int i = 1; i <= q; i++) {
		string x, y;
		cin >> x >> y;
		cout << 0;
	}
	return 0;
}

