#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
namespace furina{
	const int N = 20, mod = 998244353, inf = 0x7fffffff >> 1;
	
	inline int add(int a, int b){
		return a + b >= mod ? a + b - mod : a + b;
	}
	
	int n, m;
	char S[N + 10];
	int c[N + 10], p[N + 10];
	
	int f[1 << N][N + 10];
	
	int main(){
		cin >> n >> m;
		cin >> (S + 1);
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		
		f[0][0] = 1;
		for(int s = 0; s < (1 << n) - 1; s++){
			int cnt = 0;
			for(int i = 1; i <= n; i++)
				if((s >> (i - 1)) & 1)
					cnt++;
			for(int j = 0; j <= n; j++){
				if(!f[s][j])
					continue;
				for(int i = 1; i <= n; i++){
					if((s >> (i - 1)) & 1)
						continue;
					int t = s ^ (1 << (i - 1));
					if(j >= c[i] || S[cnt + 1] == '0')
						f[t][j + 1] = add(f[t][j + 1], f[s][j]);
					else
						f[t][j] = add(f[t][j], f[s][j]);
				}
			}
		}
		
		int ans = 0;
		for(int i = 1; i < m; i++)
			ans = add(ans, f[(1 << n) - 1][i]);
		cout << ans << '\n';
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	furina::main();
//	while(1);
	return 0;
}
