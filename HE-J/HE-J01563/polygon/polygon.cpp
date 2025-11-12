#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T> void re(T&x){x = 0; char c; int sign; do{c = getchar(); if(c == '-') sign = -1;}while(!isdigit(c)); do{x = x * 10 + c - '0'; c = getchar();}while(isdigit(c)); x *= sign;}

const int N = 5e3 + 100;
const int Mo = 998244353;

ll n;
ll I_LOVE_MYGO, ans;
ll a[N];
ll yh[10][N];

void dfs(ll id, ll sum, ll cnt){
	if (id == 0 && cnt >= 3){
		if (sum > I_LOVE_MYGO) ans ++;
		ans %= Mo;
		return;
	}
	if (id == 0) return;
	dfs(id - 1, sum + a[id], cnt + 1);
	dfs(id - 1, sum, cnt);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
//  I Love MYGO
	cin >> n;
	bool b = 0;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		if (a[i] != 1) b = 1;
	}
	if (b){
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i ++){
			I_LOVE_MYGO = a[i] * 2;
			dfs(i - 1, a[i], 1); 
			ans %= Mo;
		}
		printf("%lld", ans % Mo);
	}else {
		ll I_LOVE_LENI = 0;
		yh[1][1] = 1;
		for (int i = 1; i <= n; i ++){	
			for (int j = 1; j <= i + 1; j ++){
				yh[2][j] = (yh[1][j] % Mo + yh[1][j - 1] % Mo) % Mo;
			}
			for (int j = 1; j <= i + 1; j ++){
				yh[1][j] = yh[2][j];
			}
//			for (int j = 1; j <= i + 1; j ++){
//				printf("%lld ", yh[1][j]);
//			}
//			printf("\n"); 1 1 1 1 1 1 1 1 1 1
		}
		for (int i = 4; i <= n + 1; i ++){
			ans += yh[1][i] % Mo;
			ans %= Mo;
		}
		printf("%lld", ans);
	}
	return 0;
}

// Goodbye OI's Road

