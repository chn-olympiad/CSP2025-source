#include<bits/stdc++.h>
#define int long long
using namespace std;
int T , n;
int p[100005][5] , cnt[5] , mk[100005] , qp[100005];
signed main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while(T--){
		for(int i = 1 ; i <= 3 ; i++) cnt[i] = 0;
		cin >> n; 
		for(int i = 0 ; i <= n + 1 ; i++){
			mk[i] = qp[i] = 0;
			for(int j = 0 ; j <= 3 ; j++){
				p[i][j] = 0;
			}
		}
		int ans = 0;
		for(int i = 1 ; i <= n ; i++){
			int maxn = 0 , id;
			for(int j = 1 ; j <= 3 ; j++){
				cin >> p[i][j];
				if(p[i][j] > maxn){
					maxn = p[i][j];
					id = j;
				}
			} 
			mk[i] = id;
			ans += maxn;
			cnt[id]++;
		}
		bool flag = false;
		int jian;
		for(int i = 1 ; i <= 3 ; i++){
			if(cnt[i] > n / 2){
				jian = i;
				flag = true;
				break;
			}
		}
		if(flag == false){
			cout << ans << "\n";
			continue;
		}
		int po = 0;
		for(int i = 1 ; i <= n ; i++){
			if(mk[i] == jian){
				po++;
				qp[po] = 1e9;
				for(int j = 1 ; j <= 3 ; j++){
					if(mk[i] != j) qp[po] = min(qp[po] , p[i][mk[i]] - p[i][j]);
				}
			}
		}
		sort(qp + 1 , qp + 1 + po);
		for(int i = 1 ; i <= cnt[jian] - n / 2 ; i++) ans -= qp[i];
		cout << ans << "\n";
	}
	return 0;
}
