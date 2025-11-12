#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node{
	long long a , b , c , mx;
}g[N];
bool cmp(node x , node y){
	return x.mx > y.mx;
}
bool st[N];
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t --){
		memset(st , false , sizeof(st));
		long long n;
		cin >> n;
		bool f1 = 1 , f2 = 1;
		for(int i = 1 ; i <= n ; i ++){
			long long a , b , c;
			cin >> a >> b >> c;
			if(b != 0 || c != 0) f1 = false;
			if(c != 0) f2 = false;
			int mx = max({a , b , c});
			g[i] = {a , b , c , mx};
		}
		if(n == 2){
			long long ans = -1;
			long long a = g[1].a , b = g[1].b , c = g[1].c;
			long long x = g[2].a , y = g[2].b , z = g[2].c;
			long long c1 = max(a + y , a + z);
			long long c2 = max(b + x , b + z);
			long long c3 = max(c + x , c + y);
			ans = max({c1, c2 , c3});
			cout << ans << '\n';
			return 0;
		}
		if(f1){
			long long ans = 0;
			sort(g + 1 , g + n + 1 , cmp);
			for(int i = 1 ; i <= n / 2 ; i ++){
				ans += g[i].a;
			}
			cout << ans << '\n';
			return 0;
		}
		long long cnt1 = 0, cnt2 = 0 , cnt3 = 0;
		long long tar = n / 2;
		long long ans = 0;
		sort(g + 1 , g + n + 1 , cmp);
		for(int i = 1; i <= n ; i ++){
			long long mx = g[i].mx;
			long long a = g[i].a , b = g[i].b , c = g[i].c;
			if(a == mx){
				if(cnt1 < tar){
					ans += mx;
					cnt1 ++;
				}else{
					st[i] = 1;
					continue;
				}
			}else if(b == mx){
				if(cnt2 < tar){
					ans += mx;
					cnt2 ++;
				}else{
					st[i] = 1;
					continue;
				}
			}else{
				if(cnt3 < tar){
					ans += mx;
					cnt3 ++;
				}else{
					st[i] = 1;
					continue;
				}
			}
		}
		for(int i = 1 ; i <= n ; i ++){
			if(st[i]){
				long long a = -1 , b = -1 , c = -1;
				if(cnt1 < tar){
					a = g[i].a;
				}
				if(cnt2 < tar){
					b = g[i].b;
				}
				if(cnt3 < tar){
					c = g[i].c;
				}
				long long mx = max({a , b , c});
				if(mx == a) cnt1 ++ , ans += mx;
				else if(mx == b) cnt2 ++ , ans += mx;
				else cnt3 ++ , ans += mx;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
