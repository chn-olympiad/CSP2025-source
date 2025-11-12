#include <bits/stdc++.h>
using namespace std;
int t, n, st, nd, rd;
int maxnrd(int x, int y, int z){
	if ((x > y) && (x > z) && (st <= n / 2)){
		st++;
		return x;
	}
	else if ((x < y) && (y > z) && (nd <= n / 2)){
		nd++;
		return y;
	}
	else if ((z > y) && (x < z) && (rd <= n / 2)){
		rd++;
		return z;
	}
	else if ((x = y) && (x > z)){
		if (st <= n / 2){
			st++;
			return x;
		}
		else if (nd <= n / 2){
			nd++;
			return y;
		}
		else{
			rd++;
			return z;
		}
	}
	else if ((x = z) && (x > y)){
		if (st <= n / 2){
			st++;
			return x;
		}
		else if (rd <= n / 2){
			rd++;
			return z;
		}
		else{
			nd++;
			return y;
		}
	}
	else if ((z = y) && (x < z)){
		if (rd <= n / 2){
			rd++;
			return z;
		}
		else if (nd <= n / 2){
			nd++;
			return y;
		}
		else{
			st++;
			return x;
		}
	}
	else{
		if (st <= n / 2){
			st++;
			return x;
		}
		else if (nd <= n / 2){
			nd++;
			return y;
		}
		else{
			rd++;
			return z;
		}
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		scanf("%d", &n);
		int a[100020][4] = {}, ans[100020] = {}, pos[100020][4] = {}, sum = 0;
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= 3; k++){
				scanf("%d", &a[j][k]);
				if (k == 3){
					int p = 0;
					for (int q = 1; q <= 3; q++){
						if (a[j][1] < a[j][2]){
							p = a[j][1];	a[j][1] = a[j][2];	a[j][2] = p;
						}
						if (a[j][2] < a[j][3]){
							p = a[j][2];	a[j][2] = a[j][3];	a[j][3] = p;
						}
						if (a[j][1] < a[j][3]){
							p = a[j][1];	a[j][1] = a[j][3];	a[j][3] = p;
						}
					}
				}
			}
			for (int g = 1; g <= n; g++)
				for (int h = 1; h <= 3; h++)
					pos[g][h] = a[h][g];
			for (int e = 1; e <= 3; e++)
				for (int r = 1; r <= n; r++)
					ans[r] = maxnrd(pos[1][r], pos[2][r], pos[3][r]);
		}
		for (int p = 1; p <= n; p++)	sum += ans[p];
		printf("%d\n", sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
