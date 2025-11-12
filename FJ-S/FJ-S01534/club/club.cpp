#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr)
#define N 100005

int n;
int a[N][3];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	IOS;
	int q;
	std::cin >> q;
	while(q--){
		std::cin >> n;
		std::vector< int > t;
		int cnt[3] = {};
		int ans = 0;
		for(int i = 1;i <= n;i++){
			std::cin >> a[i][0] >> a[i][1] >> a[i][2];
			int mx = 0;
			for(int j = 1;j < 3;j++){
				if(a[i][j] > a[i][mx]){
					mx = j;
				}
			}
			cnt[mx]++;
			ans += a[i][mx];
		}
		if(cnt[0] > n / 2){
			for(int i = 1;i <= n;i++){
				int mx = 0;
				for(int j = 1;j < 3;j++){
					if(a[i][j] > a[i][mx]){
						mx = j;
					}
				}
				if(mx == 0){
					t.push_back(i);
				}
			}
			sort(t.begin(),t.end(),[](int x,int y){
				int tmp1 = a[x][0] - std::max(a[x][1],a[x][2]);
				int tmp2 = a[y][0] - std::max(a[y][1],a[y][2]);
				return tmp1 < tmp2;
			});
			for(int i = 0;i < cnt[0] - n / 2;i++){
				int k = t[i];
				ans -= a[k][0] - std::max(a[k][1],a[k][2]);
			}
		}else if(cnt[1] > n / 2){
			for(int i = 1;i <= n;i++){
				int mx = 0;
				for(int j = 1;j < 3;j++){
					if(a[i][j] > a[i][mx]){
						mx = j;
					}
				}
				if(mx == 1){
					t.push_back(i);
				}
			}
			sort(t.begin(),t.end(),[](int x,int y){
				int tmp1 = a[x][1] - std::max(a[x][0],a[x][2]);
				int tmp2 = a[y][1] - std::max(a[y][0],a[y][2]);
				return tmp1 < tmp2;
			});
			for(int i = 0;i < cnt[1] - n / 2;i++){
				int k = t[i];
				ans -= a[k][1] - std::max(a[k][0],a[k][2]);
			}
		}else if(cnt[2] > n / 2){
			for(int i = 1;i <= n;i++){
				int mx = 0;
				for(int j = 1;j < 3;j++){
					if(a[i][j] > a[i][mx]){
						mx = j;
					}
				}
				if(mx == 2){
					t.push_back(i);
				}
			}
			sort(t.begin(),t.end(),[](int x,int y){
				int tmp1 = a[x][2] - std::max(a[x][1],a[x][0]);
				int tmp2 = a[y][2] - std::max(a[y][1],a[y][0]);
				return tmp1 < tmp2;
			});
			for(int i = 0;i < cnt[2] - n / 2;i++){
				int k = t[i];
				ans -= a[k][2] - std::max(a[k][0],a[k][1]);
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}

