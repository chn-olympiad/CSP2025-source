#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T, n, hh, ans, k;
int a[N][4], c[4], cha[N];
struct node{
	int num, h;
}b[N][4];
bool cmp(node x, node y){
	return x.num > y.num;
}
bool flag;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--){
		memset(c, 0, sizeof(c));
		ans = 0;
		k = 0;
		flag = false; 
		cin >> n;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=3; j++){
				cin >> a[i][j];
				b[i][j].num = a[i][j];
				b[i][j].h = j;
			}
			sort(b[i]+1, b[i]+4, cmp);
		}
		for (int i=1; i<=n; i++) ans += b[i][1].num;
		for (int i=1; i<=n; i++){
			c[b[i][1].h] ++;
			if (c[b[i][1].h]>(n/2)){
				hh = b[i][1].h;
				flag = true;
			}
		}
		if (flag==true){
			for (int i=1; i<=n; i++){
				if (b[i][1].h==hh){
					cha[++k] = b[i][1].num-b[i][2].num;
				}
			}
			sort(cha+1, cha+k+1);
			for (int i=1; i<=c[hh]-n/2; i++) ans -= cha[i];
		}
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
