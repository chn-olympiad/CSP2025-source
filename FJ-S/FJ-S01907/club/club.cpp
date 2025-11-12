#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		int n, a[100010][4];
		cin >> n;
		bool a1 = true, a2 = true;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2])a1 = false;
			if(a[i][3])a2 = false;
		}
		if(n == 2){
			cout << max(a[1][1] + a[2][2], a[1][2] + a[2][1]) << endl;
		} 
		else if(n == 4){
			int maxn = -1;
			for(int i = 1; i <= 3; i++){
				for(int j = 1; j <= 3; j++){
					for(int k = 1; k <= 3; k++){
						for(int l = 1; l <= 3; l++){
							int q[4] = {0};
							q[i]++;q[j]++;q[k]++;q[l]++;
							if(q[1] < 3 && q[2] < 3 && q[3] < 3){
								maxn = max(maxn, a[1][i]+ a[2][j] + a[3][k] + a[4][l]);
							}
						}
					}
				}
			}
			cout << maxn << endl;
		} 
		else if(n == 10){
			int q[11] = {0};
			int maxn = -1;
			for(int a1 = 1; a1 < 4; a1++){
				q[a1]++;
				for(int a2 = 1; a2 < 4; a2++){
					q[a2]++;
					for(int a3 = 1; a3 < 4; a3++){
						q[a3]++;
						for(int a4 = 1; a4 < 4; a4++){
							q[a4]++;
							for(int a5 = 1; a5 < 4; a5++){							
								q[a5]++;
								for(int a6 = 1; a6 < 4; a6++){							
									if(q[a6] < 5){
										q[a6]++;
										for(int a7 = 1; a7 < 4; a7++){
											if(q[a7] < 5){
												q[a7]++;
												for(int a8 = 1; a8 < 4; a8++){
													if(q[a8] < 5){
														q[a8]++;
														for(int a9 = 1; a9 < 4; a9++){
															if(q[a9] < 5){
																q[a9]++;
																for(int a10 = 1; a10 < 4; a10++){
																	if(q[a10] < 5){
																		q[a10]++;
																		maxn = max(maxn, a[1][a1] + a[2][a2] + a[3][a3] + a[4][a4] + a[5][a5] + a[6][a6] + a[7][a7] + a[8][a8] + a[9][a9] + a[10][a10]);
																		q[a10]--;
																	}
																}
																q[a9]--;
															}
														}
														q[a8]--;
													}
												}
												q[a7]--;
											}
										}
										q[a6]--;
									}					
								}
								q[a5]--;					
							}
							q[a4]--;
						}
						q[a3]--;
					}
					q[a2]--;
				}
				q[a1]--;
			}
			cout << maxn << endl;
		}
		else if(a2){
			if(a1){
				int b[100010] = {0};
				for(int i = 1; i <= n; i++)b[i] = a[i][1];
				sort(b + 1, b + n + 1);
				long long cnt = 0;
				for(int i = n / 2 + 1; i <= n; i++){
					cnt += b[i];
				}
				cout << cnt << endl;
			} 
		}
	}
	return 0;
}
