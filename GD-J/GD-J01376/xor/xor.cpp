#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10 , logn = 21 , maxm = 1e3 + 10;
int a[maxn];
struct edge{
	int l , r;
}x[maxn];
bool cmp(edge b , edge c){
	if(b.r == c.r) return b.l < c.l;
	else return b.r < c.r;
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	int max_1 = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		max_1 = max(max_1 , a[i]);
	}
	if(k <= 1 && max_1 <= 1){
		if(k == 1){
			int cnt = 0;
			for(int i = 1 ; i <= n ; i++){
				if(a[i]) ++cnt;
			}
			cout << cnt;
		}
		else{
			int cnt = 0 , ans = 0;
			for(int i = 1 ; i <= n ; i++){
				if(a[i]) ++cnt;
				else ans = cnt / 2 + 1 , cnt = 0;
			}
			cout << ans;
		}
	}
	else{
		int ans = 0;
		for(int i = 1 ; i <= n ; i++){
			int cnt = 0;
			for(int j = i ; j <= n ; j++){
				cnt ^= a[j];
				if(cnt == k){
					x[++ans].l = i;
					x[ans].r = j;
					break;
				}
			}
		}
		sort(x + 1 , x + 1 + ans , cmp);
		int r1 = x[1].r;
		int cnt = 1;
		for(int i = 2 ; i <= ans ; i++){
			
			if(x[i].l <= r1){
				continue;
			}
			else{
				++cnt;
				r1 = x[i].r;
			}
		}
		cout << cnt;
	}
	return 0;
}
