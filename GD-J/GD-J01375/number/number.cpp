#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e6 + 5;
int n;
char c[N];
vector<int> v;
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", c + 1);
	n = strlen(c + 1);
	for (int i = 1; i <= n; i++){
		if ('0' <= c[i] && c[i] <= '9'){
			v.push_back(c[i] - '0');
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++){
		printf("%d", v[i]);
	}
	return 0;
}
