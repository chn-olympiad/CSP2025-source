#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
string s[N][5];
string a, b;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++){
		scanf("%s%s", &s[i][1], &s[i][2]);
	}
	for (int i=1; i<=q; i++){
		scanf("%s%s", &a, &b);
		if (a.size()!=b.size() || a==b) cout << "0" << '\n';
		else{
			cout << "1" << '\n';
		}
	}
	return 0;
}
