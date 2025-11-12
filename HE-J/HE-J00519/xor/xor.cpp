#include <iostream>
#include <map>
using namespace std;

const int MXN = 5e5 + 5;
const int MXV = (1 << 20);
int n, k, a, s, t, dic[MXV];
bool vis[MXV];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	vis[0] = true;
	for (int i = 1; i <= n; i += 1){
		cin >> a;
		s ^= a;
		if (vis[s ^ k]) t = max(t, dic[s ^ k] + 1);
		vis[s] = true;
		dic[s] = max(dic[s], t);
	}
	
	cout << t;
	return 0;
}
