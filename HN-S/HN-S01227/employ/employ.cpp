#include<bits/stdc++.h>
#define int long long
#define f(i , l , r) for(int i = l;i <= r;i ++)
#define d(i , l , r) for(int i = r;i >= l;i --)
#define lowbit(x) ((x)&-(x))
#define pii pair<int,int>
#define fi first 
#define sc second
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int N = 500 + 10 , mod = 998244353;
int n , m;
string s;
int c[N] , cnt[N] , f[N][N] , suf[N] , pre[N] , jc[N] , C[N][N];
signed main(){
	fre("employ");
	cin >> n >> m >> s , s = " " + s;
	f(i , 1 , n)cin >> c[i] , cnt[c[i]] ++;
	pre[0] = cnt[0];
	f(i , 1 , n)pre[i] = pre[i-1] + cnt[i];
	d(i , 1 , n)suf[i] = suf[i+1] + cnt[i];
	jc[0] = 1;
	f(i , 1 , n)jc[i] = jc[i-1] * i % mod;
	C[0][0] = 1; 
	f(i , 1 , n){
		C[i][0] = 1;
		f(j , 1 , i){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}
	f[0][0] = 1;
	f(i , 1 , n){
		f(j , 0 , i){
			if(s[i] == '1'){
				if(j < i)f[i][j] = f[i-1][j] * max(suf[j+1] - (i - 1 - j) , 0ll) % mod;
				if(j > 0)f[i][j] = (f[i][j] + f[i-1][j-1] * (pre[j-1] - (j - 1))) % mod;
			}
		}
	}
	int ans = 0;
//	f(i , 1 , n){
//		f(j , 0 , n){
//			cout << f[i][j] << " ";
//		}
//		cout << "\n";
//	}
	f(i , 0,  n){
		if(n - i >= m)ans = (ans + f[n][i]) % mod;
	}
	cout << ans << "\n";
}
/*
3 2
101
1 1 2

100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/
