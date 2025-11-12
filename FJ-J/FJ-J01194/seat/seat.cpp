#include<bits/stdc++.h>
using namespace std;
int a[105],seat[105][105],p = 0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	p = a[1];sort(a + 1,a+n*m+1,greater<int>());
	int x = 1,y = 1,add = 1;for (int i = 1;i <= n * m;i++){
		//cout << y << " " << x << "--\n";
		seat[x][y] = a[i];
		if (x == 1 && i > 1){
			add = 1,y++;
			seat[x][y] = a[++i];
			x+=add;
		}else if (x == n){
			add = -1,y++;
			seat[x][y] = a[++i];
			x+=add;
		}else x += add;
	}
	int r = 0,c = 0;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			//cout << seat[i][j] << " ";
			if (seat[i][j] == p){
				r = i,c = j;
				break;
			}
		}
		//cout << "\n";
		if (r && c) break;
	}cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
