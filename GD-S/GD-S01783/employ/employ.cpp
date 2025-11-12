#include<bits/stdc++.h>
using namespace std;
const int N = 505, MOD = 998244353;
int n, m, f[1 << 18][20], c[N];
string s;
void add(int &x, int y){
	((x += y) >= MOD)? (x -= y) : x;
}
int pc(int x){
	int cnt = 0;
	while(x)
		x ^= x & (-x), cnt++;
	return cnt;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	if(m == n){
		bool flag = 1;
		for(int i = 0; i < n; i++)
			flag &= (s[i] == '1');
		for(int i = 0; i < n; i++)
			flag &= (c[i] != 0);
		if(flag){
			long long ret = 1;
			for(int i = 2; i <= n; i++)
				ret = ret * i % MOD;
			cout << ret << "\n";
		}
		else
			cout << "0\n";
		return 0;
	}
	f[0][0] = 1;
	for(int msk = 1; msk < (1 << n); msk++){
		for(int i = 0, k = pc(msk); i < n; i++){
			for(int j = 0; j < n; j++){
				if((msk >> j) & 1){
//					if(msk == 2)
//						cout << i << "\n";
					if(s[k - 1] == '0' || i >= c[j])
						add(f[msk][i + 1], f[msk ^ (1 << j)][i]);
					else{
						add(f[msk][i], f[msk ^ (1 << j)][i]);
					}
				}
			}
		}
	}
//	cout << f[2][0] << "\n";
	int sum = 0;
	for(int i = 0; i <= n - m; i++)
		add(sum, f[(1 << n) - 1][i]);
	cout << sum << "\n";
}
