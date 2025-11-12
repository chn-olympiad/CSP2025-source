#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n, m, g, l, cnt = 1;cin >> n >> m >> g;
	for(int i = 2;i <= n * m; i++){
		//互不相同
		cin >> l;
		if(l > g) cnt++;
	}
	int k = cnt % n, p = cnt / n;
	if(k != 0) p++;
	if(p % 2 == 1){
		for(int jh = 1;jh <= n; jh++){
			if((p - 1) * n + jh == cnt){
				return cout << p << ' ' << jh << '\n', 0;
			}
		}
	}else {
		for(int jh = n;jh >= 1; jh--){
			if((p - 1) * n + n - jh + 1 == cnt){
				return cout << p << ' ' << jh << '\n', 0;
			}
		}
	}
	return 0;
}
/*




*/