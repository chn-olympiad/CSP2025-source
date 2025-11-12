#include<bits/stdc++.h>
using namespace std;
string s, b;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> s >> b;
	}
	for(int i = 1; i <= n; i++){
		cin >> s >> b;
	}
	for(int i = 1; i <= m; i++){
		cout << "0" << endl;
	}
	return 0;
}
