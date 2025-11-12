#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string s[n][2];
	string t[q][2];
	for (int i = 0; i < n; i++){
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 0; i < q; i++){
		cin >> t[i][0] >> t[i][1];
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
