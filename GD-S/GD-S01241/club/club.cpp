#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct edge{
	int f , s , t , x;
}a[maxn]; 
int fi , se , thi;
bool cmp(edge z , edge y){
	if(z.x == y.x){
		return max({z.f , z.s , z.t}) - z.x > max({y.f , y.s , y.t}) - y.x;
	}
	else{
		return z.x > y.x;
	}
}
int maxx(int i){
	int mx = max({a[i].f , a[i].s , a[i].t});
	if(mx == a[i].f){
		return 1;
	}
	else if(mx == a[i].s){
		return 2;
	}
	else return 3;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int n;
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int ans = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i].f >> a[i].s >> a[i].t;
			int sum = a[i].f + a[i].s + a[i].t;
			a[i].x =  2 * max({a[i].f , a[i].s , a[i].t}) + min({a[i].f , a[i].s , a[i].t}) - sum;
			fi = se = thi = 0;
		}
		sort(a + 1 , a + 1 + n , cmp);
		for(int i = 1 ; i <= n ; i++){
			int m = maxx(i);
			if(m == 1){
				if(fi < n / 2){
					ans += a[i].f;
					fi++;
				}
				else{
					a[i].f = 0;
					m = maxx(i);
					if(m == 2){
						ans += a[i].s;
						se++;
					}
					else{
						ans += a[i].t;
						thi++;
					}
				}
			}
			else if(m == 2){
				if(se < n / 2){
					ans += a[i].s;
					se++;
				}
				else{
					a[i].s = 0;
					m = maxx(i);
					if(m == 1){
						ans += a[i].f;
						fi++;
					}
					else{
						ans += a[i].t;
						thi++;
					}
				}
			}
			else{
				if(thi < n / 2){
					ans += a[i].t;
					thi++;
				}
				else{
					a[i].t = 0;
					m = maxx(i);
					if(m == 2){
						ans += a[i].s;
						se++;
					}
					else{
						ans += a[i].f;
						fi++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
