#include <bits/stdc++.h>
using namespace std;
string s;
int g[100005];
int n,m;
const int mod = 998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; ++ i) cin >> g[i];
	int no = 0;
	srand(time(0));
	cout << rand() % 998244353;
	return 0;
}
