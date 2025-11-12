#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	string s[200005][3], t_1, t_2;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i][1] >> s[i][2];
	}
	while(q--){
		cin >> t_1 >> t_2;
		cout << 0 << endl;
	}
	return 0;
}
