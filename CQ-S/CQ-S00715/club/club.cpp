#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100010;
namespace cza{
	int T;
	int n;
	int a[N][4];
	int tmp[4][N], tcnt[4];
	bool cmp1(int x, int y){
		return max(a[x][2], a[x][3]) - a[x][1] > max(a[y][2], a[y][3]) - a[y][1];
	}
	bool cmp2(int x, int y){
		return max(a[x][1], a[x][3]) - a[x][2] > max(a[y][1], a[y][3]) - a[y][2];
	}
	bool cmp3(int x, int y){
		return max(a[x][1], a[x][2]) - a[x][3] > max(a[y][1], a[y][2]) - a[y][3];
	}
	int main(){
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
		ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
		cin >> T;
		while(T--){
			tcnt[1] = tcnt[2] = tcnt[3] = 0;
			int ans = 0;
			cin >> n;
			for(int i = 1; i <= n; i++){
				cin >> a[i][1] >> a[i][2] >> a[i][3];
				if(a[i][1] >= a[i][2] and a[i][1] >= a[i][3]){
					tmp[1][++tcnt[1]] = i;
					ans += a[i][1];
				}else if(a[i][2] >= a[i][1] and a[i][2] >= a[i][3]){
					tmp[2][++tcnt[2]] = i;
					ans += a[i][2];
				}else{
					tmp[3][++tcnt[3]] = i;
					ans += a[i][3];
				}
			}
			if(tcnt[1] > n / 2){
				sort(tmp[1] + 1, tmp[1] + 1 + tcnt[1], cmp1);
				for(int i = 1; i <= tcnt[1] - n / 2; i++){
					int x = tmp[1][i];
					ans += max(a[x][2], a[x][3]) - a[x][1];
				}
			}else if(tcnt[2] > n / 2){
				sort(tmp[2] + 1, tmp[2] + 1 + tcnt[2], cmp2);
				for(int i = 1; i <= tcnt[2] - n / 2; i++){
					int x = tmp[2][i];
					ans += max(a[x][1], a[x][3]) - a[x][2];
				}
			}else if(tcnt[3] > n / 2){
				sort(tmp[3] + 1, tmp[3] + 1 + tcnt[3], cmp3);
				for(int i = 1; i <= tcnt[3] - n / 2; i++){
					int x = tmp[3][i];
					ans += max(a[x][1], a[x][2]) - a[x][3];
				}
			}
			cout << ans << '\n';
		}
		return 0;
	}
}
signed main(){
	return cza::main();
}
/*
14:52 ²»ÏëÅÄ 
*/
