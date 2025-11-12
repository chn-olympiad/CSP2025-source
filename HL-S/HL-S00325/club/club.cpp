#include <iostream> // 60pts?
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
constexpr int N = 1e5 + 10;

struct Node {
	int a, b, c;
} w[N];

int n;
ll dp[210][210][210];

ll dfs(int i, int A, int B) {
	if(i == n + 1) return 0;
	if(dp[i][A][B] != -1) return dp[i][A][B];
	ll ans = -1;
	if(A < n / 2) ans = max(ans, dfs(i + 1, A + 1, B) + w[i].a);
	if(B < n / 2) ans = max(ans, dfs(i + 1, A, B + 1) + w[i].b);
	if(i - A - B < n / 2) ans = max(ans, dfs(i + 1, A, B) + w[i].c);
	return dp[i][A][B] = ans;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int T; cin>>T;
	while(T--) {
		cin>>n;
		for(int i = 1;i <= n;i++) {
			cin>>w[i].a>>w[i].b>>w[i].c;
		}
		if(n <= 200) {
			memset(dp, -1, sizeof(dp));
			cout<<dfs(1, 0, 0)<<"\n";
		} else {
			set <int> t;
			for(int i = 1;i <= n;i++) {
				t.insert(w[i].a);
				t.insert(w[i].b);
				t.insert(w[i].c);
			}
			ll sum = 0;
			for(int i = 1;i <= n;i++) {
				sum += *t.begin();
				t.erase(t.begin());
			}
		}
	}
	return 0;
}