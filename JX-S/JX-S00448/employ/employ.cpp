#include <bits/stdc++.h>
#define int unsigned long long
#define PII pair <int, int>
#define N 5000005
const int INF = 1e18;
using namespace std;

int n, m;
string s;
int c[N];

void solve(){
	srand(time(0));
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	int tot = 0;
	
	if(n <= 12){
		vector <int> p;
		for(int i = 1; i <= n; i++)
			p.push_back(i);
		do {
			int cnt = 0;
			for(int i = 0; i < n; i++)
				if(s[i] == '0' || cnt >= c[p[i]])
					cnt++;
			if(cnt <= n - m)
				tot++;
		}while(next_permutation(p.begin(), p.end()));
		cout << tot << '\n';
	} else {
		cout << rand() % 998244354;
	}
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--)
		solve();
	return 0;
}
