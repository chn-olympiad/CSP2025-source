#include <iostream>
#include <string>
using namespace std;

const int N = 500,mod = 998244353;

int c[N + 5],lis[N + 5],n,m;
long long ret = 0;
bool book[N + 5];
string s;

void dfs(int i) {
	if (i == n + 1) {
		int cnt = 0,cntM = 0;
		for (int i = 1;i <= n;i++) {
			if (cnt < c[lis[i]] && s[i] == '1') {
				cntM++;
			} else {
				cnt++;
			}
		}
		
		if (cntM >= m) {
			ret = (ret + 1) % mod;
		}
		return ;
	}
	
	for (int j = 1;j <= n;j++) {
		if (book[j]) {
			continue;
		}
		
		lis[i] = j;
		book[j] = true;
		
		dfs(i + 1);
		
		book[j] = false;
	}
	
	return ;
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m >> s;
	
	for (int i = 1;i <= n;i++) {
		cin >> c[i];
	}
	
	s = " " + s; 
	dfs(1);
	
	cout << ret << endl;
	return 0;
}
