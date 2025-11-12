// CSP 2025 RP++
/* \gcx ls/ \gcx ls/*/ 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pii pair<int, int> 
#define N 1010

string s;
ll v[N]; 

int main() {
	cin.tie(0);
	cout.tie(0);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int cnt = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			v[cnt] = ((int)(s[i] - '0'));
			cnt++;
		}
	}
 
	sort(v + 1, v + cnt + 1);
	
	for (int i = cnt; i >= 2; i--) {
		cout << v[i];
	}
	
	return 0;
}
