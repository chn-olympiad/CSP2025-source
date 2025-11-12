#include<bits/stdc++.h>
using namespace std;
long long t,n,x,y,z,ma;
long long a[100005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%ld",&t);
	for(int i = 1;i <= t;i++){
		scanf("%ld",&n);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				scanf("%ld",&a[i][j]);
			} 
		}
		if(n == 2){
			ma = 0;
			for(int i = 1;i <= 3;i++){
				for(int j = 1;j <= 3;j++){
					if(i == 1)	x++;
					if(i == 2)	y++;
					if(i == 3)	z++;
					
					if(j == 1)	x++;
					if(j == 2)	y++;
					if(j == 3)	z++;
					if(x <= n / 2 && y <= n / 2 && z <= n / 2){
						if(a[1][i] + a[2][j] > ma)	ma = a[1][i] + a[2][j];
					}
					x = 0,y = 0,z = 0;
				}
			}
			printf("%d\n",ma);
		}
		if(n == 4){
			ma = 0;
			for(int k = 1;k <= 3;k++){
				for(int l = 1;l <= 3;l++){
					for(int i = 1;i <= 3;i++){
						for(int j = 1;j <= 3;j++){
							if(i == 1)	x++;
							if(i == 2)	y++;
							if(i == 3)	z++;
						
							if(j == 1)	x++;
							if(j == 2)	y++;
							if(j == 3)	z++;
						
							if(k == 1)	x++;
							if(k == 2)	y++;
							if(k == 3)	z++;
						
							if(l == 1)	x++;
							if(l == 2)	y++;
							if(l == 3)	z++;
							if(x <= n / 2 && y <= n / 2 && z <= n / 2){
								if(a[1][k] + a[2][l] + a[3][i] + a[4][j] > ma){
									ma = a[1][k] + a[2][l] + a[3][i] + a[4][j];
								}	
							}
							x = 0,y = 0,z = 0;
						}
					}
				}
			}
			printf("%d\n",ma);
		}
		if(n == 10){
			ma = 0;
			for(int b = 1;b <= 3;b++){
				for(int c = 1;c <= 3;c++){
					for(int d = 1;d <= 3;d++){
						for(int e = 1;e <= 3;e++){
							for(int f = 1;f <= 3;f++){
								for(int g = 1;g <=3;g++){
									for(int k = 1;k <= 3;k++){
										for(int l = 1;l <= 3;l++){
											for(int i = 1;i <= 3;i++){
												for(int j = 1;j <= 3;j++){
													if(i == 1)	x++;
													if(i == 2)	y++;
													if(i == 3)	z++;
						
													if(j == 1)	x++;
													if(j == 2)	y++;
													if(j == 3)	z++;
						
													if(k == 1)	x++;
													if(k == 2)	y++;
													if(k == 3)	z++;
						
													if(l == 1)	x++;
													if(l == 2)	y++;
													if(l == 3)	z++;
													
													if(b == 1)	x++;
													if(b == 2)	y++;
													if(b == 3)	z++;
													
													if(c == 1)	x++;
													if(c == 2)	y++;
													if(c == 3)	z++;
													
													if(d == 1)	x++;
													if(d == 2)	y++;
													if(d == 3)	z++;
													
													if(e == 1)	x++;
													if(e == 2)	y++;
													if(e == 3)	z++;
													
													if(f == 1)	x++;
													if(f == 2)	y++;
													if(f == 3)	z++;
													
													if(g == 1)	x++;
													if(g == 2)	y++;
													if(g == 3)	z++;
													if(x <= n / 2 && y <= n / 2 && z <= n / 2){
														if(a[1][b] + a[2][c] + a[3][d] + a[4][e] + a[5][f] + a[6][g] + a[7][k] + a[8][l] + a[9][i] + a[10][j] > ma)	ma = a[1][b] + a[2][c] + a[3][d] + a[4][e] + a[5][f] + a[6][g] + a[7][k] + a[8][l] + a[9][i] + a[10][j];
													}
													x = 0,y = 0,z = 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			printf("%d\n",ma);
		}
	}
	return 0;
} 
