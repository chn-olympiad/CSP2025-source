#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
//#define int long long
//#define int unsigned long long
/*
T1 ended at 8:39
*/
using namespace std;
const int N = 1e6;
string s; 
map <int,int> num;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if('0' <= s[i] && s[i] <= '9') num[s[i]-'0']++;
	}
	for(int i = 9; i >= 0; i--)
		for(int j = 1; j <= num[i]; j++) cout << i;
	return 0;
}

