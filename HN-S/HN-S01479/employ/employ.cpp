#include <bits/stdc++.h>
using namespace std;
int n, sum = 0, m;
string s;
vector<int>x[3];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= s.size(); i++){
		if(s[i] == '1') sum++;
	}
	if(sum < m) cout << 0;
	return 0;
}
