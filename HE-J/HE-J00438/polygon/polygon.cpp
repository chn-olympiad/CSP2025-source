#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T>inline void read(T &x){
	char c;int sign = 1;x = 0;
	do{c = getchar();if(c == '-') sign = -1;} while (! isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();} while (isdigit(c));
	x *= sign;
}
template <typename T>inline void wr(T x){
	if (x < 0){putchar('-');x = -x;};
	if (x > 9) wr(x / 10);
	putchar((x % 10) | 48);
}

const int N = 5e3 + 5,mod = 998244353;
int n,a[N];
int dp[N][N],ans;
//bool vis[N];
inline void dfs(int x,int k,int s,int i){
	if (x > i) return ;
	if (k >= 2 && x == i){
		if (s + a[i] > a[i] * 2){
			ans ++;
			ans %= mod;
//			for ( int j = 1; j < i; j ++){
//				if (vis[j]){
//					wr(j);putchar(' ');
//				}
//			}
//			wr(i);putchar('\n');
		}
	}
//	vis[x] = 1;
	dfs(x + 1,k + 1,s + a[x],i);
//	vis[x] = 0;
	dfs(x + 1,k,s,i);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	read(n);
	for ( int i = 1; i <= n; i ++){
		read(a[i]);
	}
	sort(a + 1,a + n + 1);
	for ( int i = 3; i <= n; i ++){
//		int k = a[i] * 2;
		dfs(1,0,0,i);
	}
	
	wr(ans);
	return 0;
}
