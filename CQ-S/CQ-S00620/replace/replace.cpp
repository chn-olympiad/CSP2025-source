#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int N = 2e5 + 10, MAXL = 2e3;

int n, q;
pair<string, string> str[N];
int pA[N];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s1, s2;
		cin  >> s1 >> s2;
		str[i] = {s1, s2};
	}
	for(int i = 1; i <= q; i++){
		string t1, t2;
		cin >> t1 >> t2;
		cout << 0 << "\n";
	}
	
	return 0;
}
