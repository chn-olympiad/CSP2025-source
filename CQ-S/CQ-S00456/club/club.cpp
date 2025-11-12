#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
namespace furina{
	const int N = 1e5, inf = 0x7fffffff >> 1;
	
	int n;
	int a[N + 10][3], p[N + 10];
	
	int now[3];
	
	int fnn[N + 10], cnt;
	
	inline void solve(){
		cin >> n;
		ll sum = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			pair<int, int> ans = make_pair(0, 0);
			ans = max(ans, {a[i][0], 0});
			ans = max(ans, {a[i][1], 1});
			ans = max(ans, {a[i][2], 2});
			sum += ans.first, now[p[i] = ans.second]++;
		}
		
		if(now[0] <= (n >> 1) && now[1] <= (n >> 1) && now[2] <= (n >> 1))
			cout << sum << '\n';
		else{
			int op = -1;
			if(now[0] > (n >> 1))
				op = 0;
			if(now[1] > (n >> 1))
				op = 1;
			if(now[2] > (n >> 1))
				op = 2;
			
			for(int i = 1; i <= n; i++){
				if(p[i] != op)
					continue;
				int mx = 0;
				if(op != 0)
					mx = max(mx, a[i][0]);
				if(op != 1)
					mx = max(mx, a[i][1]);
				if(op != 2)
					mx = max(mx, a[i][2]);
				fnn[++cnt] = mx - a[i][op];
			}
			sort(fnn + 1, fnn + cnt + 1);
			while(now[op] > (n >> 1)){
				now[op]--;
				sum += fnn[cnt--];
			}
			cout << sum << '\n';
		}
	}
	
	inline void clear(){
		cnt = 0;
		now[0] = now[1] = now[2] = 0;
	}
	
	int main(){
		int T;
		cin >> T;
		while(T--)
			solve(), clear();
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	furina::main();
//	while(1);
	return 0;
}
