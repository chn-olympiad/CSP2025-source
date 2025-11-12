#include<bits/stdc++.h>
using namespace std;
struct E{
	int num, id, ne;
}x[330001];
int t, n, tot, a[4][100001], cnt[4], ans, ji;
bool va[100001], vb[100001], vc[100001];
bool cmp(E p, E q){
	return p.num > q.num; 
}
void solve(){
	if(n == 2){
		int ans = 0;
		for(int i = 1; i <= 3; i++){
			for(int j = 1; j <= 3; j++){
				if(i != j){
//					cout << i << ' ' << j << ' ' << ' ' << a[1][i] << ' ' << a[2][j] << '\n';
					ans = max(ans, a[i][1] + a[j][2]);
				}
			}
		}
		cout << ans << endl;
		return;
	}
//	if(n == 4){
//		int ans = 0;
//		for(int i = 1; i <= 3; i++){
//			for(int j = 1; j <= 3; j++){
//				for(int k = 1; k <= 3; k++){
//					for(int l = 1; l <= 3; l++){
//						if(((i == j) && (k == l)) || ((i == k) && (j == l))	|| ((i == l) && (j == k))){
//							ans = max(ans, a[i][1] + a[j][2] + a[k][3] + a[l][4]);
//							cout << i <<' ' << j << ' ' << k <<' ' << l << '\n';
//						}
//					}
//				}
//			}
//		}
//		cout << ans << endl;
//		return;
//	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
//		cout << 'a'; 
		memset(va, 0, sizeof(va));
		memset(cnt, 0, sizeof(cnt));
		ans = 0;
		tot = 0;
		ji = 0;
		cin >> n;
		bool d1 = 0, d2 = 0, d3 = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			x[++tot].num = a[1][i];
			x[tot].id = 1;
			x[tot].ne = i;
			x[++tot].num = a[2][i];
			x[tot].id = 2;
			x[tot].ne = i;
			x[++tot].num = a[3][i];
			x[tot].id = 3;
			x[tot].ne = i;
		}
		sort(x + 1, x + 1 + tot, cmp);
//		if(!d1 && !d2){
//			for(int )	
//		}
//		for(int i = 1; i <= tot; i++){
//			cout << x[i].num << ' ';
//		}
//		cout << '\n';
//		for(int j = 1; j <= n; j++){
//			int ans1 = 0;
			if(n <= 2){
				solve();
				continue;
			}
			for(int i = 1; i <= tot; i++){
				if(ji == n){
	//				cout << 'a';
					break;
				}
				if((cnt[x[i].id] < n / 2) && (!va[x[i].ne])){
	//				cout << 'A';
	//				cout << i << ' ' << x[i].num << ' ' << x[i].id << ' ' << x[i].ne << ' ' << ji << '\n';
					ans += x[i].num; 
					cnt[x[i].id]++;
					va[x[i].ne] = 1; 
					ji++;
				}
			
//			cout << ans1 << '\n';
//			ans = max(ans, ans1);	
		}
//		cout << ji << '\n';
		cout << ans << endl;
	}
} 
