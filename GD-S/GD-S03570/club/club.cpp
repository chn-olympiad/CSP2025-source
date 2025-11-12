//70pts
#include<bits/stdc++.h>
//bool Mst;
#define ll long long
using namespace std;
const int N = 1e5 + 10;
const int M = 210;
int T, n;
ll ans/*, dp[N]*/;		//¹ö¶¯Êý×é 
ll dp1[M][M][M];
struct node{
	int a, b, c;
}w[N];
bool cmp(node x, node y){
	return x.a - x.b > y.a - y.b;
}
void init(){
	for(int t = 1; t <= n; ++t){
		for(int i = 0; i <= n / 2; ++i){
			for(int j = 0; j <= n / 2; ++j){
				int k = t - i - j;
				if(k < 0 || k > n / 2) continue;
				dp1[t][i][j] = 0;
			}
		}
	}
//	for(int i = 1; i <= n; ++i) dp[i] = 0;
	ans = 0;
	return ;
}

//bool Med;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cerr << abs((&Med) - (&Mst)) / 1024.0 / 1024 << "MB\n";
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		init();
		for(int i = 1; i <= n; ++i)
			cin >> w[i].a >> w[i].b >> w[i].c;
		
		sort(w + 1, w + n + 1, cmp);
		
		if(n <= 200){
			for(int t = 1; t <= n; ++t){
				for(int i = 0; i <= n / 2; ++i){
					for(int j = 0; j <= n / 2; ++j){
						int k = t - i - j;
						if(k < 0 || k > n / 2) continue;
						if(i > 0) dp1[t][i][j] = max(dp1[t][i][j], dp1[t - 1][i - 1][j] + w[t].a);
						if(j > 0) dp1[t][i][j] = max(dp1[t][i][j], dp1[t - 1][i][j - 1] + w[t].b);
						if(k > 0) dp1[t][i][j] = max(dp1[t][i][j], dp1[t - 1][i][j] + w[t].c);
	//					cerr << "dp1[" << t << "][" << i << "][" << j << "] is " << dp1[t][i][j] << '\n';
					}
				}
			}
			for(int i = 0; i <= n / 2; ++i){
				for(int j = 0; j <= n / 2; ++j){
					int k = n - i - j;
					if(k < 0 && k > n / 2) continue;
					ans = max(ans, dp1[n][i][j]);
				}
			}
	//		cerr << '\n';
			cout << ans << '\n';
			continue;
		}
		else {
			int ans = 0;
			for(int i = 1; i <= n / 2; ++i) ans += w[i].a;
			for(int i = n / 2 + 1; i <= n; ++i) ans += w[i].b;
			cout << ans << '\n';
		}
		
	}
	
	return 0;
}
