#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, t;
struct N{
	int pos, data;
}a[MAXN][5];
struct Num{
	int max, umax;
};
vector<Num> p[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= 3;i++) p[i] = {}; 
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j].data;
				a[i][j].pos = j;
			}
		}
		long long ans = 0
		for(int i = 1;i <= n;i++){
			sort(a[i] + 1, a[i] + 4, [](N x, N y){
				return x.data > y.data;
			});
			p[a[i][1].pos].push_back({a[i][1].data, a[i][2].data});
			ans += a[i][1].data;
		}
		for(int i = 1;i <= 3;i++){
			if(p[i].size() > n / 2){
				int len = p[i].size();
				sort(p[i].begin(), p[i].end(), [](Num x, Num y){
					return x.max - x.umax < y.max - y.umax;
				});
				for(int j = 0;j < len - n / 2;j++){
					ans -= p[i][j].max - p[i][j].umax;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
