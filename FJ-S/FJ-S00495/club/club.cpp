#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int countp = 0,n,a[MAXN][5] = {0},st[MAXN] = {0},ans = 0;
//int superbigcup(int b[3],int l){
//	if (l == 0){
//		if (b[0] > b[1]&&b[0] > b[2]) return 0;
//		else if (b[1] > b[0]&&b[1] > b[2]) return 1;
//		else return 2;
//	}else if (l == 1){
//		if (b[0] > b[1]&&b[0] > b[2]){
//			if(b[1] > b[2])return 1;
//			else return 2;
//		}else if (b[1] > b[0]&&b[1] > b[2]){
//			if(b[0] > b[2]) return 0;
//			else return 2;
//		}else {
//			if(b[0] > b[1]) return 0;
//			else return 1;
//		}
//	}else{
//		if (b[0] > b[1]&&b[0] > b[2]){
//			if(b[1] > b[2])return 2;
//			else return 1;
//		}else if (b[1] > b[0]&&b[1] > b[2]){
//			if(b[0] > b[2]) return 2;
//			else return 0;
//		}else {
//			if(b[0] > b[1]) return 1;
//			else return 0;
//		}
//	}
//}
void dfs(int time,int answer){
	if(time == n){
		if (answer > ans){
			ans = answer;
			//cout << ans << endl;
		}
		return;
	}
	for (int i = 0;i < 3;i++){
		if(st[i] <= countp - 1) {
			st[i]++;
			//cout << i << " " << st[i] << endl;
			//cout << countp << endl;
			time++;
			dfs(time,answer+a[time-1][i]);
			time--;
			st[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int b[MAXN][5];
		ans = -1;
		cin >> n;
		countp = floor(n/2);
		for (int i = 0;i < n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
//		for (int i = 0;i < n;i++){
//			st[i] = 0;
//			int maxb = -799,maxbst,maxv = -799;
//			for (int j = 0;j < n;j++){
//				int test = superbigcup(b[j],0),test2 = superbigcup(b[j],1);
//				if (b[j][test] > maxb) {
//					maxb = b[j][test];
//					maxv = superbigcup(b[j],1);
//					maxbst = j;
//				}else if(b[j][test] == maxb && test2 > maxv){
//					maxb = b[j][test];
//					maxv = superbigcup(b[j],1);
//					maxbst = j;
//				}
//			}
//			for(int j = 0;j < 3;j++){
//				a[i][j] = b[maxbst][j];
//				b[maxbst][j] = -1;
//			}
//		}
//		for(int k = 0;k < n;k++){
//			for(int j = 0;j < 3;j++){
//				cout << a[k][j] << " ";
//			}
//			cout << endl;
//		}
//			cout << endl;
//		for(int i = 0;i < n;i++){
//			int tmp1,tmp2,tmp3;
//			if(st[tmp1 = superbigcup(a[i],0)] <= countp - 1){
//				st[tmp1]++;
//				cout << st[tmp1];
//				ans += a[i][tmp1];
//			}else if (st[tmp2 = superbigcup(a[i],1)] <= countp - 1){
//				st[tmp2]++;
//				ans += a[i][tmp2];
//			}else {
//				st[tmp3 = superbigcup(a[i],2)]++;
//				ans += a[i][tmp3]++;
//			}
//		}
		dfs(0,0);
		cout << ans << endl;
		for (int i = 0;i <= n;i++){
			for(int j = 0;j < 3;j++){
				a[i][j] = 0;
			}
		}
	}
	return 0;
}
