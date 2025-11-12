#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;

const int S = 1e6+5;
string s;
int a[S];

bool cmp(int a, int b){
	return a > b;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	IOS;
	cin >> s;
	int len = s.size();
	memset(a, -1, sizeof(a));
	for(int i=0; i<len; i++) {
		if('0' <= s[i] && s[i] <= '9'){
			a[i] = s[i] - '0';
		}
	}
	sort(a, a+len, cmp);
	for(int i=0; i<len; i++){
		if(a[i] == -1){
			break;
		}
		cout << a[i];
	}
	cout << endl;
	return 0;
}

