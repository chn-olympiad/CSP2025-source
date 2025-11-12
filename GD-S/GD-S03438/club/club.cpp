#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int T;
int n;
struct uct{
	int o[N];
	int m;
	void clear(){
		m = 0;
	}
	void add(int x){
		o[++m] = x;
	}
	void sot(){
		sort(o+1, o+m+1);
	}
}a, b, c;
int main(){
	//is long long?
	//The N is enough?
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		a.clear();
		b.clear();
		c.clear();
		int ans = 0;
		for(int i = 1; i <= n; i++){
			int x, y, z;
			cin >> x >> y >> z;
			int maxn = max(max(x, y), z);
			if(maxn == x) a.add(x-max(y, z));
			else if(maxn == y) b.add(y-max(x, z));
			else c.add(z-max(x, y));
			ans += maxn;
		}
		n = n/2;
		a.sot();
		b.sot();
		c.sot();
		if(a.m > n) for(int i = 1; i <= a.m-n; i++) ans -= a.o[i];
		if(b.m > n) for(int i = 1; i <= b.m-n; i++) ans -= b.o[i];
		if(c.m > n) for(int i = 1; i <= c.m-n; i++) ans -= c.o[i];
		cout << ans << '\n';
	}
	return 0;
} 
