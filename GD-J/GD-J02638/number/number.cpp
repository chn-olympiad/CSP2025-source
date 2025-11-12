#include<bits/stdc++.h>
#define long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;

const int N = 1e6 + 10;
string s; 
int a[N], idx;
signed main(){
	fin("number.in");
	fout("number.out");
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[idx++] = s[i] - 48;
		}
	}
	sort(a, a + idx);
	for(int i = idx - 1; i >= 0; i--) cout << a[i];
	return 0;
}

