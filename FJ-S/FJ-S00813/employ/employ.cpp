#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 998244353;
int n , m;
char s[505]; int c[505];

namespace baoli{
	int p[15]; bool vis[15];
	int ans;
	void dfs(int x){
		if(x > n){
			int sum = 0;
			for(int i = 1;i <= n;i++){
				if(sum >= c[p[i]]){ sum++; continue; }
				if(s[i] == '0'){ sum++; continue; }
			}
			ans += (n - sum >= m);
			return ;
		}
		for(int i = 1;i <= n;i++){
			if(vis[i]) continue;
			vis[i] = 1;
			p[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}

namespace yaya {
	int f[19][262200][19];
	
	void solve(){
		const int N = (1 << n) - 1;
		memset(f , 0 , sizeof(f));
		f[0][0][0] = 1;
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j < N;j++) if(__builtin_popcount(j) == i - 1){
				for(int k = 1;k <= n;k++) if(!(j >> (k - 1) & 1)){
					int nw = j ^ (1 << (k - 1));
					for(int fail = 0;fail < i;fail++){
						if(fail >= c[k] || s[i] == '0'){
							if((f[i][nw][fail + 1] += f[i - 1][j][fail]) >= MOD)
								f[i][nw][fail + 1] -= MOD;
						}
						else{
							if((f[i][nw][fail] += f[i - 1][j][fail]) >= MOD)
								f[i][nw][fail] -= MOD;
						}
					}
				}
			}
		}
		
		int ans = 0;
		m = n - m;
		for(int i = 0;i <= m;i++)
			if((ans += f[n][N][i]) >= MOD) ans -= MOD;
		printf("%d\n" , ans);
 	}
}

int main(void){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	scanf("%s" , s + 1);
	for(int i = 1;i <= n;i++) scanf("%d" , &c[i]);
	sort(c + 1 , c + 1 + n);
	if(n <= 10){
		baoli::dfs(1);
		printf("%d\n" , baoli::ans);
		return 0;
	}
	else 
		yaya::solve();
	return 0;
}
