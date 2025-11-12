#include <bits/stdc++.h> 
using namespace std;
int a[114514][11],t,n,vis[11];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int maxn = 0;
		cin >> n;
		for(int i = 1 ; i <= n ; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[1][2] == 0 && a[1][3] == 0){
			int b[114514];
			for(int i = 1 ; i <= n ; i++) b[i] = a[i][1];
			sort(b+1,b+n+1);
			for(int i = n ; i > n / 2 ; i--) maxn += b[i];
		}
		else if(a[1][1] == 0 && a[1][3] == 0){
			int b[114514];
			for(int i = 1 ; i <= n ; i++) b[i] = a[i][2];
			sort(b+1,b+n+1);
			for(int i = n ; i > n / 2 ; i--) maxn += b[i];
		}
		else if(a[1][1] == 0 && a[1][2] == 0){
			int b[114514];
			for(int i = 1 ; i <= n ; i++) b[i] = a[i][3];
			sort(b+1,b+n+1);
			for(int i = n ; i > n / 2 ; i--) maxn += b[i];
		}
		else if(n == 2){
			for(int i1 = 1 ; i1 <= 3 ; i1++){
				for(int i2 = 1 ; i2 <= 3 ; i2++){
					memset(vis,0,sizeof(vis));
					vis[i1]++,vis[i2]++;
					if(vis[1] <= n / 2 && vis[2] <= n / 2 && vis[3] <= n / 2) maxn = max(maxn,a[1][i1]+a[2][i2]);
				}
			}
		}
		else if(n == 3){
			for(int i1 = 1 ; i1 <= 3 ; i1++){
				for(int i2 = 1 ; i2 <= 3 ; i2++){
					for(int i3 = 1 ; i3 <= 3 ; i3++){
						memset(vis,0,sizeof(vis));
						vis[i1]++,vis[i2]++,vis[i3]++;
						if(vis[1] <= n / 2 && vis[2] <= n / 2 && vis[3] <= n / 2) maxn = max(maxn,a[1][i1]+a[2][i2]+a[3][i3]);
					}
				}
			}
		}
		else if(n == 4){
			for(int i1 = 1 ; i1 <= 3 ; i1++){
				for(int i2 = 1 ; i2 <= 3 ; i2++){
					for(int i3 = 1 ; i3 <= 3 ; i3++){
						for(int i4 = 1 ; i4 <= 3 ; i4++){
							memset(vis,0,sizeof(vis));
							vis[i1]++,vis[i2]++,vis[i3]++,vis[i4]++;
							if(vis[1] <= n / 2 && vis[2] <= n / 2 && vis[3] <= n / 2) maxn = max(maxn,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]);
						}
					}
				}
			}
		}
		else if(n == 5){
			for(int i1 = 1 ; i1 <= 3 ; i1++){
				for(int i2 = 1 ; i2 <= 3 ; i2++){
					for(int i3 = 1 ; i3 <= 3 ; i3++){
						for(int i4 = 1 ; i4 <= 3 ; i4++){
							for(int i5 = 1 ; i5 <= 3 ; i5++){
								memset(vis,0,sizeof(vis));
								vis[i1]++,vis[i2]++,vis[i3]++,vis[i4]++,vis[i5]++;
							                  	if(vis[1] <= n / 2 && vis[2] <= n / 2 && vis[3] <= n / 2) maxn = max(maxn,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]);
							}
						}
					}
				}
			}
		}
		else if(n == 6){
			for(int i1 = 1 ; i1 <= 3 ; i1++){
				for(int i2 = 1 ; i2 <= 3 ; i2++){
					for(int i3 = 1 ; i3 <= 3 ; i3++){
						for(int i4 = 1 ; i4 <= 3 ; i4++){
							for(int i5 = 1 ; i5 <= 3 ; i5++){
								for(int i6 = 1 ; i6 <= 3 ; i6++){
									memset(vis,0,sizeof(vis));
									vis[i1]++,vis[i2]++,vis[i3]++,vis[i4]++,vis[i5]++,vis[i6]++;
									if(vis[1] <= n / 2 && vis[2] <= n / 2 && vis[3] <= n / 2) maxn = max(maxn,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]);
								}
							}
						}
					}
				}
			}
		}
		else if(n == 7){
			for(int i1 = 1 ; i1 <= 3 ; i1++){
				for(int i2 = 1 ; i2 <= 3 ; i2++){
					for(int i3 = 1 ; i3 <= 3 ; i3++){
						for(int i4 = 1 ; i4 <= 3 ; i4++){
							for(int i5 = 1 ; i5 <= 3 ; i5++){
								for(int i6 = 1 ; i6 <= 3 ; i6++){
									for(int i7 = 1 ; i7 <= 3 ; i7++){
										memset(vis,0,sizeof(vis));
										vis[i1]++,vis[i2]++,vis[i3]++,vis[i4]++,vis[i5]++,vis[i6]++,vis[i7]++;
										if(vis[1] <= n / 2 && vis[2] <= n / 2 && vis[3] <= n / 2) maxn = max(maxn,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]);
									}
								}
							}
						}
					}
				}
			}
		}
		else if(n == 8){
			for(int i1 = 1 ; i1 <= 3 ; i1++){
				for(int i2 = 1 ; i2 <= 3 ; i2++){
					for(int i3 = 1 ; i3 <= 3 ; i3++){
						for(int i4 = 1 ; i4 <= 3 ; i4++){
							for(int i5 = 1 ; i5 <= 3 ; i5++){
								for(int i6 = 1 ; i6 <= 3 ; i6++){
									for(int i7 = 1 ; i7 <= 3 ; i7++){
										for(int i8 = 1 ; i8 <= 3 ; i8++){
											memset(vis,0,sizeof(vis));
											vis[i1]++,vis[i2]++,vis[i3]++,vis[i4]++,vis[i5]++,vis[i6]++,vis[i7]++,vis[i8]++;
											if(vis[1] <= n / 2 && vis[2] <= n / 2 && vis[3] <= n / 2) maxn = max(maxn,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else if(n == 9){
			for(int i1 = 1 ; i1 <= 3 ; i1++){
				for(int i2 = 1 ; i2 <= 3 ; i2++){
					for(int i3 = 1 ; i3 <= 3 ; i3++){
						for(int i4 = 1 ; i4 <= 3 ; i4++){
							for(int i5 = 1 ; i5 <= 3 ; i5++){
								for(int i6 = 1 ; i6 <= 3 ; i6++){
									for(int i7 = 1 ; i7 <= 3 ; i7++){
										for(int i8 = 1 ; i8 <= 3 ; i8++){
											for(int i9 = 1 ; i9 <= 3 ; i9++){
												memset(vis,0,sizeof(vis));
												vis[i1]++,vis[i2]++,vis[i3]++,vis[i4]++,vis[i5]++,vis[i6]++,vis[i7]++,vis[i8]++,vis[i9]++;
												if(vis[1] <= n / 2 && vis[2] <= n / 2 && vis[3] <= n / 2) maxn = max(maxn,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]+a[9][i9]);
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
		else if(n == 10){
			for(int i1 = 1 ; i1 <= 3 ; i1++){
				for(int i2 = 1 ; i2 <= 3 ; i2++){
					for(int i3 = 1 ; i3 <= 3 ; i3++){
						for(int i4 = 1 ; i4 <= 3 ; i4++){
							for(int i5 = 1 ; i5 <= 3 ; i5++){
								for(int i6 = 1 ; i6 <= 3 ; i6++){
									for(int i7 = 1 ; i7 <= 3 ; i7++){
										for(int i8 = 1 ; i8 <= 3 ; i8++){
											for(int i9 = 1 ; i9 <= 3 ; i9++){
												for(int i10 = 1 ; i10 <= 3 ; i10++){
													memset(vis,0,sizeof(vis));
													vis[i1]++,vis[i2]++,vis[i3]++,vis[i4]++,vis[i5]++,vis[i6]++,vis[i7]++,vis[i8]++,vis[i9]++,vis[i10]++;
													if(vis[1] <= n / 2 && vis[2] <= n / 2 && vis[3] <= n / 2)  maxn = max(maxn,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]+a[9][i9]+a[10][i10]);
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
		}
		else for(int i = 1 ; i <= n ; i++) maxn += max(a[i][1],max(a[i][2],a[i][3]));
		cout << maxn << endl;
	}
	return 0;
}
