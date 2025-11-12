#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
const int INF = 1e9+7;
const ll LLINF = (ll)1e18+7;
const lf LFINF = (lf)1e18+7;
const int maxn = 1e5+5;
const int maxm = 2e5+5;
int T, N, M, K, Q;
ll a[maxn][5];
priority_queue<ll, vector<ll>, greater<ll> > st[5];

bool inline isdig(const char &ch){
	return ch >= '0' && ch <= '9';
}

template <typename type>
void inline read(type &x){
	x = 0; type f = 1;
	char ch = getchar();
	while (!isdig(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdig(ch)) x = x*10+ch-'0', ch = getchar();
	x = x*f;
} 

void init(){
	for (int i = 1; i <= 3; i++) while (!st[i].empty()) st[i].pop();
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	read(T);
	while (T--){
		read(N);
		init();
		
		ll ans = 0;
		for (int i = 1; i <= N; i++){
			int loc = 1;
			for (int j = 1; j <= 3; j++){
				read(a[i][j]);
				if (a[i][loc] < a[i][j]) loc = j;
			}
			
			ll val = LLINF;
			for (int j = 1; j <= 3; j++){
				if (j != loc) val = min(val, a[i][loc]-a[i][j]);
			}
			
			ans += a[i][loc];
			st[loc].push(val);
		}
		
		for (int i = 1; i <= 3; i++){
			while (st[i].size() > N/2){
				ans -= st[i].top();
				st[i].pop();
			}
		}
		
		printf("%lld\n", ans);
	}
	
	
	return 0;
}
