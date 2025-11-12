/*
clear && ulimit -s 1024000 && g++ % -o %< -O2 -std=c++14 -DLOCAL -Wall -Wextra -Wshadow -Wconversion && ulimit -v 128000 && time ./%< && size %<
clear && ulimit -s 1024000 && g++ % -o %< -O2 -std=c++14 -DLOCAL -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined -g && ./%<
echo && cat out.out && echo
*/
#include <bits/stdc++.h>
using namespace std;
using llt = long long;
using llf = long double;
using ull = unsigned long long;
template<class T> void Cmin(T &a, T b){ if(a > b) a = b; }
template<class T> void Cmax(T &a, T b){ if(a < b) a = b; }
#define endl '\n'
#ifdef LOCAL
FILE *InFile = freopen("in.in", "r", stdin), *OutFile = freopen("out.out", "w", stdout);
#else
FILE *InFile = freopen("club.in", "r", stdin), *OutFile = freopen("club.out", "w", stdout);
#endif

const int N = 1e5 + 3;
int n, aas, _a[N][3], ct[3], chs[N];

void Solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int ma = -1, &p = chs[i] = 0;
		for(auto j : {0, 1, 2}){
			cin >> _a[i][j];
			if(ma < _a[i][j]) ma = _a[i][j], p = j;
		}
		++ct[p], aas += ma;
	}
	for(auto j : {0, 1, 2}) if(ct[j] > (n >> 1)){
		vector<int> vec;
		for(int i = 1; i <= n; ++i) if(chs[i] == j){
			int ma = -1;
			for(auto j : {0, 1, 2}) if(j != chs[i]) Cmax(ma, _a[i][j]);
			vec.emplace_back(_a[i][chs[i]] - ma);
		}
		sort(vec.begin(), vec.end());
		for(auto k : vec) if(ct[j] > (n >> 1)) aas -= k, --ct[j];
	}
	cout << aas << endl;
}
void Clear(){ aas = 0, ct[0] = ct[1] = ct[2] = 0; }

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--) Solve(), Clear();
}
