#include <bits./stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define ll long long

int read(){
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	} 
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int t , n , cnt = 0 , a[N] , b[N] , c[N];
ll ans = 0;

void dfs(int pos , int ta , int tb , int tc , ll sum){
	if(pos == n + 2) return;
	
	ans = max(ans , sum);		
	if(ta < (n >> 1))
		dfs(pos + 1 , ta + 1 , tb , tc , sum + a[pos]);
	if(tb < (n >> 1))
		dfs(pos + 1 , ta , tb + 1 , tc , sum + b[pos]);
	if(tc < (n >> 1))
		dfs(pos + 1 , ta , tb , tc + 1 , sum + c[pos]);
}

void solve(){
	n = read();
	ans = 0;
	memset(a , 0 , sizeof(a));
	memset(b , 0 , sizeof(b));
	memset(c , 0 , sizeof(c));	
	for(int i = 1; i <= n; i++)
		a[i] = read() , b[i] = read() , c[i] = read();
	dfs(1 , 0 , 0 , 0 , 0);
	cout << ans << "\n";
}

int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	t = read();

	while(t--)
		solve();
	return 0;
} 
