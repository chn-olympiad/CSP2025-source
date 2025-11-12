#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1e5+5;
struct LHY{
	int tot,d[4];
}f[N][4];
struct P{
	int ist[4],px[4];
}a[N];
int T,n,ans = -114514,t[28];

int calc(){
	int res = 0;
	for(int i = 1;i <= n;i++){
		res += a[i].ist[t[i]];
	}
	return res;
}

void makep(int x){
	if(x == n){
		ans = max(ans,calc());
		return;
	}
	for(int i = 1;i <= 3;i++){
		t[x+1] = i;
		if(count(t+1,t+x+1+1,i) > n/2) continue;
		makep(x+1);
	} 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				f[i][j].tot = f[i][j].d[1] = f[i][j].d[2] = f[i][j].d[3] = 0;
				cin >> a[i].ist[j];
				a[i].px[j] = a[i].ist[j];
			}
			sort(a[i].px+1,a[i].px+3+1,greater<int>());
		}
		if(n <= 13){
			ans = -114514;
//			memset(t,0,sizeof t);
//			memset(cnt,0,sizeof cnt);
			makep(0);
			cout << ans << '\n';
			continue;
		}
		sort(a+1,a+n+1,
			[](const P &x,const P &y){
				if(x.px[0] != y.px[0]) return x.px[0] > y.px[0];
				if(x.px[1] != y.px[1]) return x.px[1] > y.px[1];
				return x.px[2] > y.px[2];
			}
		);
//		for(int i = 1;i <= n;i++){
//			for(int j = 1;j <= 3;j++){
//				cout << a[i].ist[j] << ' ';
//			}
//			cout << '\n';
//		}
		for(int i = 1;i <= 3;i++){
			f[1][i].tot = a[1].ist[i];
			f[1][i].d[i] = 1;
		}
		for(int i = 2;i <= n;i++){
			sort(f[i-1]+1,f[i-1]+3+1,
				[](const LHY &x,const LHY &y){
					return x.tot > y.tot;
				}
			);
			for(int j = 1;j <= 3;j++){
				for(int k = 1;k <= 3;k++){
					if(f[i-1][k].d[j] < n/2){
						f[i][j] = f[i-1][k];
						f[i][j].tot = f[i-1][k].tot + a[i].ist[j];
						f[i][j].d[j]++;
						break;
					}
				}
			}
		}
		cout << max({f[n][1].tot,f[n][2].tot,f[n][3].tot}) << '\n';
	}

	return 0;
}
