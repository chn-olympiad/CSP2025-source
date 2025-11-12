#include<bits/stdc++.h>
#define int long long 
#define pii pair<int, int>
using namespace std;
const int INF=0x3f3f3f3f;
int a[200];
string s, ans;
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i=0; i<s.size(); i++) if (s[i] >= '0' && s[i] <= '9') a[s[i]-'0']++;
	for (int i=9; i>=0; i--){
		while (a[i]){
			ans+=char(i+'0');
			a[i]--;
		}
	}
	cout << ans;
	return 0;
}
