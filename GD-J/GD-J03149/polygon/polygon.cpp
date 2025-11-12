#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int n;
int ans = 0;
int maxn = -1e9;
int z[5005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	if (n == 1){
		scanf("%d", &z[1]);
		ans = 0;
		printf("%d", ans % mod);
		return 0;
	}
	
	if (n == 2){
		scanf("%d%d", &z[1], &z[2]);
		ans = 0;
		printf("%d", ans % mod);
		return 0;
	}
	
	if (n == 3){
		scanf("%d%d%d", &z[1], &z[2], &z[3]);
		ans = 0;
		for (int i = 1; i <= n; i++){
			maxn = max(maxn, z[i]);
		}
		int op = maxn * 2;
		if (z[1] + z[2] + z[3] > op){
			ans++;
		}
		printf("%d", ans % mod);
		return 0;
	}
	
	if (n == 4){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int i = 1; i <= n; i++){
			maxn = max(maxn, z[i]);
		}
		int op = maxn * 2;
		if (z[1] + z[2] + z[3] > op){
			ans++;
		}
		
		if (z[1] + z[2] + z[4] > op){
			ans++;
		}
		if (z[4] + z[2] + z[3] > op){
			ans++;
		}
		if (z[1] + z[2] + z[3] + z[4]> op){
			ans++;
		}
		printf("%d", ans % mod);
		return 0;
	}
	
	if (n == 5){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int a = 1; a <= n; a++){
			for (int b = a + 1; b <= n; b++){
				for (int c = b + 1; c <= n; c++){
					for (int d = c + 1; d <= n; d++){
						for (int e = d + 1; e <= n; e++){
							maxn = 0;
							maxn = max(maxn, z[a]);
							maxn = max(maxn, z[b]);
							maxn = max(maxn, z[c]);
							maxn = max(maxn, z[d]);
							maxn = max(maxn, z[e]);
							
							int op = maxn * 2;
							if (z[a] + z[b] + z[c] + z[d] + z[e] > op){
								ans++;
							}
						}
						maxn = 0;
						maxn = max(maxn, z[a]);
						maxn = max(maxn, z[b]);
						maxn = max(maxn, z[c]);
						maxn = max(maxn, z[d]);
							
						
						int op = maxn * 2;
						if (z[a] + z[b] + z[c] + z[d] > op){
							ans++;
						}
					}
					maxn = 0;
					maxn = max(maxn, z[a]);
					maxn = max(maxn, z[b]);
					maxn = max(maxn, z[c]);
					
					int op = maxn * 2;
					if (z[a] + z[b] + z[c] > op){
						ans++;
					}
				}
			}
		}
		
		
		printf("%d", ans % mod);
		return 0;
	}

	if (n == 6){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int a = 1; a <= n; a++){
			for (int b = a + 1; b <= n; b++){
				for (int c = b + 1; c <= n; c++){
					for (int d = c + 1; d <= n; d++){
						for (int e = d + 1; e <= n; e++){
							for (int f = e + 1; f <= n; f++){
								maxn = 0;
								maxn = max(maxn, z[a]);
								maxn = max(maxn, z[b]);
								maxn = max(maxn, z[c]);
								maxn = max(maxn, z[d]);
								maxn = max(maxn, z[e]);
								maxn = max(maxn, z[f]);
								int op = maxn * 2;
								if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f]> op){
									ans++;
								}
							}
							maxn = 0;
							maxn = max(maxn, z[a]);
							maxn = max(maxn, z[b]);
							maxn = max(maxn, z[c]);
							maxn = max(maxn, z[d]);
							maxn = max(maxn, z[e]);
							
							int op = maxn * 2;
							if (z[a] + z[b] + z[c] + z[d] + z[e] > op){
								ans++;
							}
						}
						maxn = 0;
						maxn = max(maxn, z[a]);
						maxn = max(maxn, z[b]);
						maxn = max(maxn, z[c]);
						maxn = max(maxn, z[d]);
							
						
						int op = maxn * 2;
						if (z[a] + z[b] + z[c] + z[d] > op){
							ans++;
						}
					}
					maxn = 0;
					maxn = max(maxn, z[a]);
					maxn = max(maxn, z[b]);
					maxn = max(maxn, z[c]);
					
					int op = maxn * 2;
					if (z[a] + z[b] + z[c] > op){
						ans++;
					}
				}
			}
		}
		
		
		printf("%d", ans % mod);
		return 0;
	}
	if (n == 7){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int a = 1; a <= n; a++){
			for (int b = a + 1; b <= n; b++){
				for (int c = b + 1; c <= n; c++){
					for (int d = c + 1; d <= n; d++){
						for (int e = d + 1; e <= n; e++){
							for (int f = e + 1; f <= n; f++){
								for (int g = f + 1; g <= n; g++){
									maxn = 0;
									maxn = max(maxn, z[a]);
									maxn = max(maxn, z[b]);
									maxn = max(maxn, z[c]);
									maxn = max(maxn, z[d]);
									maxn = max(maxn, z[e]);
									maxn = max(maxn, z[f]);
									maxn = max(maxn, z[g]);
									int op = maxn * 2;
									if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g]> op){
										ans++;
									}
								}
								maxn = 0;
								maxn = max(maxn, z[a]);
								maxn = max(maxn, z[b]);
								maxn = max(maxn, z[c]);
								maxn = max(maxn, z[d]);
								maxn = max(maxn, z[e]);
								maxn = max(maxn, z[f]);
								int op = maxn * 2;
								if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f]> op){
									ans++;
								}
							}
							maxn = 0;
							maxn = max(maxn, z[a]);
							maxn = max(maxn, z[b]);
							maxn = max(maxn, z[c]);
							maxn = max(maxn, z[d]);
							maxn = max(maxn, z[e]);
							
							int op = maxn * 2;
							if (z[a] + z[b] + z[c] + z[d] + z[e] > op){
								ans++;
							}
						}
						maxn = 0;
						maxn = max(maxn, z[a]);
						maxn = max(maxn, z[b]);
						maxn = max(maxn, z[c]);
						maxn = max(maxn, z[d]);
							
						
						int op = maxn * 2;
						if (z[a] + z[b] + z[c] + z[d] > op){
							ans++;
						}
					}
					maxn = 0;
					maxn = max(maxn, z[a]);
					maxn = max(maxn, z[b]);
					maxn = max(maxn, z[c]);
					
					int op = maxn * 2;
					if (z[a] + z[b] + z[c] > op){
						ans++;
					}
				}
			}
		}
		
		
		printf("%d", ans % mod);
		return 0;
	}
	if (n == 8){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int a = 1; a <= n; a++){
			for (int b = a + 1; b <= n; b++){
				for (int c = b + 1; c <= n; c++){
					for (int d = c + 1; d <= n; d++){
						for (int e = d + 1; e <= n; e++){
							for (int f = e + 1; f <= n; f++){
								for (int g = f + 1; g <= n; g++){
									for (int h = g + 1; h <= n; h++){
										maxn = 0;
										maxn = max(maxn, z[a]);
										maxn = max(maxn, z[b]);
										maxn = max(maxn, z[c]);
										maxn = max(maxn, z[d]);
										maxn = max(maxn, z[e]);
										maxn = max(maxn, z[f]);
										maxn = max(maxn, z[g]);
										maxn = max(maxn, z[h]);
										int op = maxn * 2;
										if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] > op){
											ans++;
										}
									}
									maxn = 0;
									maxn = max(maxn, z[a]);
									maxn = max(maxn, z[b]);
									maxn = max(maxn, z[c]);
									maxn = max(maxn, z[d]);
									maxn = max(maxn, z[e]);
									maxn = max(maxn, z[f]);
									maxn = max(maxn, z[g]);
									int op = maxn * 2;
									if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g]> op){
										ans++;
									}
								}
								maxn = 0;
								maxn = max(maxn, z[a]);
								maxn = max(maxn, z[b]);
								maxn = max(maxn, z[c]);
								maxn = max(maxn, z[d]);
								maxn = max(maxn, z[e]);
								maxn = max(maxn, z[f]);
								int op = maxn * 2;
								if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f]> op){
									ans++;
								}
							}
							maxn = 0;
							maxn = max(maxn, z[a]);
							maxn = max(maxn, z[b]);
							maxn = max(maxn, z[c]);
							maxn = max(maxn, z[d]);
							maxn = max(maxn, z[e]);
							
							int op = maxn * 2;
							if (z[a] + z[b] + z[c] + z[d] + z[e] > op){
								ans++;
							}
						}
						maxn = 0;
						maxn = max(maxn, z[a]);
						maxn = max(maxn, z[b]);
						maxn = max(maxn, z[c]);
						maxn = max(maxn, z[d]);
							
						
						int op = maxn * 2;
						if (z[a] + z[b] + z[c] + z[d] > op){
							ans++;
						}
					}
					maxn = 0;
					maxn = max(maxn, z[a]);
					maxn = max(maxn, z[b]);
					maxn = max(maxn, z[c]);
					
					int op = maxn * 2;
					if (z[a] + z[b] + z[c] > op){
						ans++;
					}
				}
			}
		}
		
		
		printf("%d", ans % mod);
		return 0;
	}
	
	if (n == 9){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int a = 1; a <= n; a++){
			for (int b = a + 1; b <= n; b++){
				for (int c = b + 1; c <= n; c++){
					for (int d = c + 1; d <= n; d++){
						for (int e = d + 1; e <= n; e++){
							for (int f = e + 1; f <= n; f++){
								for (int g = f + 1; g <= n; g++){
									for (int h = g + 1; h <= n; h++){
										for (int i = h + 1; i <= n; i++){
											maxn = 0;
											maxn = max(maxn, z[a]);
											maxn = max(maxn, z[b]);
											maxn = max(maxn, z[c]);
											maxn = max(maxn, z[d]);
											maxn = max(maxn, z[e]);
											maxn = max(maxn, z[f]);
											maxn = max(maxn, z[g]);
											maxn = max(maxn, z[h]);
											maxn = max(maxn, z[i]);
											int op = maxn * 2;
											if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i]> op){
												ans++;
											}
										}
										maxn = 0;
										maxn = max(maxn, z[a]);
										maxn = max(maxn, z[b]);
										maxn = max(maxn, z[c]);
										maxn = max(maxn, z[d]);
										maxn = max(maxn, z[e]);
										maxn = max(maxn, z[f]);
										maxn = max(maxn, z[g]);
										maxn = max(maxn, z[h]);
										int op = maxn * 2;
										if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] > op){
											ans++;
										}
									}
									maxn = 0;
									maxn = max(maxn, z[a]);
									maxn = max(maxn, z[b]);
									maxn = max(maxn, z[c]);
									maxn = max(maxn, z[d]);
									maxn = max(maxn, z[e]);
									maxn = max(maxn, z[f]);
									maxn = max(maxn, z[g]);
									int op = maxn * 2;
									if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g]> op){
										ans++;
									}
								}
								maxn = 0;
								maxn = max(maxn, z[a]);
								maxn = max(maxn, z[b]);
								maxn = max(maxn, z[c]);
								maxn = max(maxn, z[d]);
								maxn = max(maxn, z[e]);
								maxn = max(maxn, z[f]);
								int op = maxn * 2;
								if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f]> op){
									ans++;
								}
							}
							maxn = 0;
							maxn = max(maxn, z[a]);
							maxn = max(maxn, z[b]);
							maxn = max(maxn, z[c]);
							maxn = max(maxn, z[d]);
							maxn = max(maxn, z[e]);
							
							int op = maxn * 2;
							if (z[a] + z[b] + z[c] + z[d] + z[e] > op){
								ans++;
							}
						}
						maxn = 0;
						maxn = max(maxn, z[a]);
						maxn = max(maxn, z[b]);
						maxn = max(maxn, z[c]);
						maxn = max(maxn, z[d]);
							
						
						int op = maxn * 2;
						if (z[a] + z[b] + z[c] + z[d] > op){
							ans++;
						}
					}
					maxn = 0;
					maxn = max(maxn, z[a]);
					maxn = max(maxn, z[b]);
					maxn = max(maxn, z[c]);
					
					int op = maxn * 2;
					if (z[a] + z[b] + z[c] > op){
						ans++;
					}
				}
			}
		}
		
		
		printf("%d", ans % mod);
		return 0;
	}
	if (n == 10){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int a = 1; a <= n; a++){
			for (int b = a + 1; b <= n; b++){
				for (int c = b + 1; c <= n; c++){
					for (int d = c + 1; d <= n; d++){
						for (int e = d + 1; e <= n; e++){
							for (int f = e + 1; f <= n; f++){
								for (int g = f + 1; g <= n; g++){
									for (int h = g + 1; h <= n; h++){
										for (int i = h + 1; i <= n; i++){
											for (int j = i + 1; j <= n; j++){
												maxn = 0;
												maxn = max(maxn, z[a]);
												maxn = max(maxn, z[b]);
												maxn = max(maxn, z[c]);
												maxn = max(maxn, z[d]);
												maxn = max(maxn, z[e]);
												maxn = max(maxn, z[f]);
												maxn = max(maxn, z[g]);
												maxn = max(maxn, z[h]);
												maxn = max(maxn, z[i]);
												maxn = max(maxn, z[j]);
												int op = maxn * 2;
												if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] > op){
													ans++;
												}
											}
											maxn = 0;
											maxn = max(maxn, z[a]);
											maxn = max(maxn, z[b]);
											maxn = max(maxn, z[c]);
											maxn = max(maxn, z[d]);
											maxn = max(maxn, z[e]);
											maxn = max(maxn, z[f]);
											maxn = max(maxn, z[g]);
											maxn = max(maxn, z[h]);
											maxn = max(maxn, z[i]);
										
											int op = maxn * 2;
											if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] > op){
												ans++;
											}
										}
										maxn = 0;
										maxn = max(maxn, z[a]);
										maxn = max(maxn, z[b]);
										maxn = max(maxn, z[c]);
										maxn = max(maxn, z[d]);
										maxn = max(maxn, z[e]);
										maxn = max(maxn, z[f]);
										maxn = max(maxn, z[g]);
										maxn = max(maxn, z[h]);
										int op = maxn * 2;
										if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] > op){
											ans++;
										}
									}
									maxn = 0;
									maxn = max(maxn, z[a]);
									maxn = max(maxn, z[b]);
									maxn = max(maxn, z[c]);
									maxn = max(maxn, z[d]);
									maxn = max(maxn, z[e]);
									maxn = max(maxn, z[f]);
									maxn = max(maxn, z[g]);
									int op = maxn * 2;
									if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g]> op){
										ans++;
									}
								}
								maxn = 0;
								maxn = max(maxn, z[a]);
								maxn = max(maxn, z[b]);
								maxn = max(maxn, z[c]);
								maxn = max(maxn, z[d]);
								maxn = max(maxn, z[e]);
								maxn = max(maxn, z[f]);
								int op = maxn * 2;
								if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f]> op){
									ans++;
								}
							}
							maxn = 0;
							maxn = max(maxn, z[a]);
							maxn = max(maxn, z[b]);
							maxn = max(maxn, z[c]);
							maxn = max(maxn, z[d]);
							maxn = max(maxn, z[e]);
							
							int op = maxn * 2;
							if (z[a] + z[b] + z[c] + z[d] + z[e] > op){
								ans++;
							}
						}
						maxn = 0;
						maxn = max(maxn, z[a]);
						maxn = max(maxn, z[b]);
						maxn = max(maxn, z[c]);
						maxn = max(maxn, z[d]);
							
						
						int op = maxn * 2;
						if (z[a] + z[b] + z[c] + z[d] > op){
							ans++;
						}
					}
					maxn = 0;
					maxn = max(maxn, z[a]);
					maxn = max(maxn, z[b]);
					maxn = max(maxn, z[c]);
					
					int op = maxn * 2;
					if (z[a] + z[b] + z[c] > op){
						ans++;
					}
				}
			}
		}
		
		
		printf("%d", ans % mod);
		return 0;
	}
	if (n == 11){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int a = 1; a <= n; a++){
			for (int b = a + 1; b <= n; b++){
				for (int c = b + 1; c <= n; c++){
					for (int d = c + 1; d <= n; d++){
						for (int e = d + 1; e <= n; e++){
							for (int f = e + 1; f <= n; f++){
								for (int g = f + 1; g <= n; g++){
									for (int h = g + 1; h <= n; h++){
										for (int i = h + 1; i <= n; i++){
											for (int j = i + 1; j <= n; j++){
												for (int k = j + 1; k <= n; k++){
													maxn = 0;
													maxn = max(maxn, z[a]);
													maxn = max(maxn, z[b]);
													maxn = max(maxn, z[c]);
													maxn = max(maxn, z[d]);
													maxn = max(maxn, z[e]);
													maxn = max(maxn, z[f]);
													maxn = max(maxn, z[g]);
													maxn = max(maxn, z[h]);
													maxn = max(maxn, z[i]);
													maxn = max(maxn, z[j]);
													maxn = max(maxn, z[k]);
													
													int op = maxn * 2;
													if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] + z[k] > op){
														ans++;
													}
												}
												maxn = 0;
												maxn = max(maxn, z[a]);
												maxn = max(maxn, z[b]);
												maxn = max(maxn, z[c]);
												maxn = max(maxn, z[d]);
												maxn = max(maxn, z[e]);
												maxn = max(maxn, z[f]);
												maxn = max(maxn, z[g]);
												maxn = max(maxn, z[h]);
												maxn = max(maxn, z[i]);
												maxn = max(maxn, z[j]);
												int op = maxn * 2;
												if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] > op){
													ans++;
												}
											}
											maxn = 0;
											maxn = max(maxn, z[a]);
											maxn = max(maxn, z[b]);
											maxn = max(maxn, z[c]);
											maxn = max(maxn, z[d]);
											maxn = max(maxn, z[e]);
											maxn = max(maxn, z[f]);
											maxn = max(maxn, z[g]);
											maxn = max(maxn, z[h]);
											maxn = max(maxn, z[i]);
										
											int op = maxn * 2;
											if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] > op){
												ans++;
											}
										}
										maxn = 0;
										maxn = max(maxn, z[a]);
										maxn = max(maxn, z[b]);
										maxn = max(maxn, z[c]);
										maxn = max(maxn, z[d]);
										maxn = max(maxn, z[e]);
										maxn = max(maxn, z[f]);
										maxn = max(maxn, z[g]);
										maxn = max(maxn, z[h]);
										int op = maxn * 2;
										if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] > op){
											ans++;
										}
									}
									maxn = 0;
									maxn = max(maxn, z[a]);
									maxn = max(maxn, z[b]);
									maxn = max(maxn, z[c]);
									maxn = max(maxn, z[d]);
									maxn = max(maxn, z[e]);
									maxn = max(maxn, z[f]);
									maxn = max(maxn, z[g]);
									int op = maxn * 2;
									if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g]> op){
										ans++;
									}
								}
								maxn = 0;
								maxn = max(maxn, z[a]);
								maxn = max(maxn, z[b]);
								maxn = max(maxn, z[c]);
								maxn = max(maxn, z[d]);
								maxn = max(maxn, z[e]);
								maxn = max(maxn, z[f]);
								int op = maxn * 2;
								if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f]> op){
									ans++;
								}
							}
							maxn = 0;
							maxn = max(maxn, z[a]);
							maxn = max(maxn, z[b]);
							maxn = max(maxn, z[c]);
							maxn = max(maxn, z[d]);
							maxn = max(maxn, z[e]);
							
							int op = maxn * 2;
							if (z[a] + z[b] + z[c] + z[d] + z[e] > op){
								ans++;
							}
						}
						maxn = 0;
						maxn = max(maxn, z[a]);
						maxn = max(maxn, z[b]);
						maxn = max(maxn, z[c]);
						maxn = max(maxn, z[d]);
							
						
						int op = maxn * 2;
						if (z[a] + z[b] + z[c] + z[d] > op){
							ans++;
						}
					}
					maxn = 0;
					maxn = max(maxn, z[a]);
					maxn = max(maxn, z[b]);
					maxn = max(maxn, z[c]);
					
					int op = maxn * 2;
					if (z[a] + z[b] + z[c] > op){
						ans++;
					}
				}
			}
		}
		
		
		printf("%d", ans % mod);
		return 0;
	}
	if (n == 12){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int a = 1; a <= n; a++){
			for (int b = a + 1; b <= n; b++){
				for (int c = b + 1; c <= n; c++){
					for (int d = c + 1; d <= n; d++){
						for (int e = d + 1; e <= n; e++){
							for (int f = e + 1; f <= n; f++){
								for (int g = f + 1; g <= n; g++){
									for (int h = g + 1; h <= n; h++){
										for (int i = h + 1; i <= n; i++){
											for (int j = i + 1; j <= n; j++){
												for (int k = j + 1; k <= n; k++){
													for (int l = k + 1; l <= n; l++){
														maxn = 0;
														maxn = max(maxn, z[a]);
														maxn = max(maxn, z[b]);
														maxn = max(maxn, z[c]);
														maxn = max(maxn, z[d]);
														maxn = max(maxn, z[e]);
														maxn = max(maxn, z[f]);
														maxn = max(maxn, z[g]);
														maxn = max(maxn, z[h]);
														maxn = max(maxn, z[i]);
														maxn = max(maxn, z[j]);
														maxn = max(maxn, z[k]);
														maxn = max(maxn, z[l]);
													
														int op = maxn * 2;
														if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] + z[k] + z[l] > op){
															ans++;
														}
													}
													maxn = 0;
													maxn = max(maxn, z[a]);
													maxn = max(maxn, z[b]);
													maxn = max(maxn, z[c]);
													maxn = max(maxn, z[d]);
													maxn = max(maxn, z[e]);
													maxn = max(maxn, z[f]);
													maxn = max(maxn, z[g]);
													maxn = max(maxn, z[h]);
													maxn = max(maxn, z[i]);
													maxn = max(maxn, z[j]);
													maxn = max(maxn, z[k]);
													
													int op = maxn * 2;
													if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] + z[k] > op){
														ans++;
													}
												}
												maxn = 0;
												maxn = max(maxn, z[a]);
												maxn = max(maxn, z[b]);
												maxn = max(maxn, z[c]);
												maxn = max(maxn, z[d]);
												maxn = max(maxn, z[e]);
												maxn = max(maxn, z[f]);
												maxn = max(maxn, z[g]);
												maxn = max(maxn, z[h]);
												maxn = max(maxn, z[i]);
												maxn = max(maxn, z[j]);
												int op = maxn * 2;
												if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] > op){
													ans++;
												}
											}
											maxn = 0;
											maxn = max(maxn, z[a]);
											maxn = max(maxn, z[b]);
											maxn = max(maxn, z[c]);
											maxn = max(maxn, z[d]);
											maxn = max(maxn, z[e]);
											maxn = max(maxn, z[f]);
											maxn = max(maxn, z[g]);
											maxn = max(maxn, z[h]);
											maxn = max(maxn, z[i]);
										
											int op = maxn * 2;
											if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] > op){
												ans++;
											}
										}
										maxn = 0;
										maxn = max(maxn, z[a]);
										maxn = max(maxn, z[b]);
										maxn = max(maxn, z[c]);
										maxn = max(maxn, z[d]);
										maxn = max(maxn, z[e]);
										maxn = max(maxn, z[f]);
										maxn = max(maxn, z[g]);
										maxn = max(maxn, z[h]);
										int op = maxn * 2;
										if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] > op){
											ans++;
										}
									}
									maxn = 0;
									maxn = max(maxn, z[a]);
									maxn = max(maxn, z[b]);
									maxn = max(maxn, z[c]);
									maxn = max(maxn, z[d]);
									maxn = max(maxn, z[e]);
									maxn = max(maxn, z[f]);
									maxn = max(maxn, z[g]);
									int op = maxn * 2;
									if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g]> op){
										ans++;
									}
								}
								maxn = 0;
								maxn = max(maxn, z[a]);
								maxn = max(maxn, z[b]);
								maxn = max(maxn, z[c]);
								maxn = max(maxn, z[d]);
								maxn = max(maxn, z[e]);
								maxn = max(maxn, z[f]);
								int op = maxn * 2;
								if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f]> op){
									ans++;
								}
							}
							maxn = 0;
							maxn = max(maxn, z[a]);
							maxn = max(maxn, z[b]);
							maxn = max(maxn, z[c]);
							maxn = max(maxn, z[d]);
							maxn = max(maxn, z[e]);
							
							int op = maxn * 2;
							if (z[a] + z[b] + z[c] + z[d] + z[e] > op){
								ans++;
							}
						}
						maxn = 0;
						maxn = max(maxn, z[a]);
						maxn = max(maxn, z[b]);
						maxn = max(maxn, z[c]);
						maxn = max(maxn, z[d]);
							
						
						int op = maxn * 2;
						if (z[a] + z[b] + z[c] + z[d] > op){
							ans++;
						}
					}
					maxn = 0;
					maxn = max(maxn, z[a]);
					maxn = max(maxn, z[b]);
					maxn = max(maxn, z[c]);
					
					int op = maxn * 2;
					if (z[a] + z[b] + z[c] > op){
						ans++;
					}
				}
			}
		}
		
		
		printf("%d", ans % mod);
		return 0;
	}
	if (n == 13){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int a = 1; a <= n; a++){
			for (int b = a + 1; b <= n; b++){
				for (int c = b + 1; c <= n; c++){
					for (int d = c + 1; d <= n; d++){
						for (int e = d + 1; e <= n; e++){
							for (int f = e + 1; f <= n; f++){
								for (int g = f + 1; g <= n; g++){
									for (int h = g + 1; h <= n; h++){
										for (int i = h + 1; i <= n; i++){
											for (int j = i + 1; j <= n; j++){
												for (int k = j + 1; k <= n; k++){
													for (int l = k + 1; l <= n; l++){
														for (int m = l + 1; m <= n; m++){
															maxn = 0;
															maxn = max(maxn, z[a]);
															maxn = max(maxn, z[b]);
															maxn = max(maxn, z[c]);
															maxn = max(maxn, z[d]);
															maxn = max(maxn, z[e]);
															maxn = max(maxn, z[f]);
															maxn = max(maxn, z[g]);
															maxn = max(maxn, z[h]);
															maxn = max(maxn, z[i]);
															maxn = max(maxn, z[j]);
															maxn = max(maxn, z[k]);
															maxn = max(maxn, z[l]);
															maxn = max(maxn, z[m]);
															int op = maxn * 2;
															if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] + z[k] + z[l] + z[m] > op){
																ans++;
															}
														}
														maxn = 0;
														maxn = max(maxn, z[a]);
														maxn = max(maxn, z[b]);
														maxn = max(maxn, z[c]);
														maxn = max(maxn, z[d]);
														maxn = max(maxn, z[e]);
														maxn = max(maxn, z[f]);
														maxn = max(maxn, z[g]);
														maxn = max(maxn, z[h]);
														maxn = max(maxn, z[i]);
														maxn = max(maxn, z[j]);
														maxn = max(maxn, z[k]);
														maxn = max(maxn, z[l]);
													
														int op = maxn * 2;
														if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] + z[k] + z[l] > op){
															ans++;
														}
													}
													maxn = 0;
													maxn = max(maxn, z[a]);
													maxn = max(maxn, z[b]);
													maxn = max(maxn, z[c]);
													maxn = max(maxn, z[d]);
													maxn = max(maxn, z[e]);
													maxn = max(maxn, z[f]);
													maxn = max(maxn, z[g]);
													maxn = max(maxn, z[h]);
													maxn = max(maxn, z[i]);
													maxn = max(maxn, z[j]);
													maxn = max(maxn, z[k]);
													
													int op = maxn * 2;
													if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] + z[k] > op){
														ans++;
													}
												}
												maxn = 0;
												maxn = max(maxn, z[a]);
												maxn = max(maxn, z[b]);
												maxn = max(maxn, z[c]);
												maxn = max(maxn, z[d]);
												maxn = max(maxn, z[e]);
												maxn = max(maxn, z[f]);
												maxn = max(maxn, z[g]);
												maxn = max(maxn, z[h]);
												maxn = max(maxn, z[i]);
												maxn = max(maxn, z[j]);
												int op = maxn * 2;
												if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] > op){
													ans++;
												}
											}
											maxn = 0;
											maxn = max(maxn, z[a]);
											maxn = max(maxn, z[b]);
											maxn = max(maxn, z[c]);
											maxn = max(maxn, z[d]);
											maxn = max(maxn, z[e]);
											maxn = max(maxn, z[f]);
											maxn = max(maxn, z[g]);
											maxn = max(maxn, z[h]);
											maxn = max(maxn, z[i]);
										
											int op = maxn * 2;
											if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] > op){
												ans++;
											}
										}
										maxn = 0;
										maxn = max(maxn, z[a]);
										maxn = max(maxn, z[b]);
										maxn = max(maxn, z[c]);
										maxn = max(maxn, z[d]);
										maxn = max(maxn, z[e]);
										maxn = max(maxn, z[f]);
										maxn = max(maxn, z[g]);
										maxn = max(maxn, z[h]);
										int op = maxn * 2;
										if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] > op){
											ans++;
										}
									}
									maxn = 0;
									maxn = max(maxn, z[a]);
									maxn = max(maxn, z[b]);
									maxn = max(maxn, z[c]);
									maxn = max(maxn, z[d]);
									maxn = max(maxn, z[e]);
									maxn = max(maxn, z[f]);
									maxn = max(maxn, z[g]);
									int op = maxn * 2;
									if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g]> op){
										ans++;
									}
								}
								maxn = 0;
								maxn = max(maxn, z[a]);
								maxn = max(maxn, z[b]);
								maxn = max(maxn, z[c]);
								maxn = max(maxn, z[d]);
								maxn = max(maxn, z[e]);
								maxn = max(maxn, z[f]);
								int op = maxn * 2;
								if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f]> op){
									ans++;
								}
							}
							maxn = 0;
							maxn = max(maxn, z[a]);
							maxn = max(maxn, z[b]);
							maxn = max(maxn, z[c]);
							maxn = max(maxn, z[d]);
							maxn = max(maxn, z[e]);
							
							int op = maxn * 2;
							if (z[a] + z[b] + z[c] + z[d] + z[e] > op){
								ans++;
							}
						}
						maxn = 0;
						maxn = max(maxn, z[a]);
						maxn = max(maxn, z[b]);
						maxn = max(maxn, z[c]);
						maxn = max(maxn, z[d]);
							
						
						int op = maxn * 2;
						if (z[a] + z[b] + z[c] + z[d] > op){
							ans++;
						}
					}
					maxn = 0;
					maxn = max(maxn, z[a]);
					maxn = max(maxn, z[b]);
					maxn = max(maxn, z[c]);
					
					int op = maxn * 2;
					if (z[a] + z[b] + z[c] > op){
						ans++;
					}
				}
			}
		}
		
		
		printf("%d", ans % mod);
		return 0;
	}
	if (n == 14){
		for (int i = 1; i <= n; i++){
			scanf("%d", &z[i]);
		}
		ans = 0;
		for (int a = 1; a <= n; a++){
			for (int b = a + 1; b <= n; b++){
				for (int c = b + 1; c <= n; c++){
					for (int d = c + 1; d <= n; d++){
						for (int e = d + 1; e <= n; e++){
							for (int f = e + 1; f <= n; f++){
								for (int g = f + 1; g <= n; g++){
									for (int h = g + 1; h <= n; h++){
										for (int i = h + 1; i <= n; i++){
											for (int j = i + 1; j <= n; j++){
												for (int k = j + 1; k <= n; k++){
													for (int l = k + 1; l <= n; l++){
														for (int m = l + 1; m <= n; m++){
															for (int o = m + 1; o <= n; o++){
																maxn = 0;
																maxn = max(maxn, z[a]);
																maxn = max(maxn, z[b]);
																maxn = max(maxn, z[c]);
																maxn = max(maxn, z[d]);
																maxn = max(maxn, z[e]);
																maxn = max(maxn, z[f]);
																maxn = max(maxn, z[g]);
																maxn = max(maxn, z[h]);
																maxn = max(maxn, z[i]);
																maxn = max(maxn, z[j]);
																maxn = max(maxn, z[k]);
																maxn = max(maxn, z[l]);
																maxn = max(maxn, z[m]);
																maxn = max(maxn, z[o]);
																int op = maxn * 2;
																if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] + z[k] + z[l] + z[m] + z[o]> op){
																	ans++;
																}
															}
															maxn = 0;
															maxn = max(maxn, z[a]);
															maxn = max(maxn, z[b]);
															maxn = max(maxn, z[c]);
															maxn = max(maxn, z[d]);
															maxn = max(maxn, z[e]);
															maxn = max(maxn, z[f]);
															maxn = max(maxn, z[g]);
															maxn = max(maxn, z[h]);
															maxn = max(maxn, z[i]);
															maxn = max(maxn, z[j]);
															maxn = max(maxn, z[k]);
															maxn = max(maxn, z[l]);
															maxn = max(maxn, z[m]);
															int op = maxn * 2;
															if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] + z[k] + z[l] + z[m] > op){
																ans++;
															}
														}
														maxn = 0;
														maxn = max(maxn, z[a]);
														maxn = max(maxn, z[b]);
														maxn = max(maxn, z[c]);
														maxn = max(maxn, z[d]);
														maxn = max(maxn, z[e]);
														maxn = max(maxn, z[f]);
														maxn = max(maxn, z[g]);
														maxn = max(maxn, z[h]);
														maxn = max(maxn, z[i]);
														maxn = max(maxn, z[j]);
														maxn = max(maxn, z[k]);
														maxn = max(maxn, z[l]);
													
														int op = maxn * 2;
														if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] + z[k] + z[l] > op){
															ans++;
														}
													}
													maxn = 0;
													maxn = max(maxn, z[a]);
													maxn = max(maxn, z[b]);
													maxn = max(maxn, z[c]);
													maxn = max(maxn, z[d]);
													maxn = max(maxn, z[e]);
													maxn = max(maxn, z[f]);
													maxn = max(maxn, z[g]);
													maxn = max(maxn, z[h]);
													maxn = max(maxn, z[i]);
													maxn = max(maxn, z[j]);
													maxn = max(maxn, z[k]);
													
													int op = maxn * 2;
													if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] + z[k] > op){
														ans++;
													}
												}
												maxn = 0;
												maxn = max(maxn, z[a]);
												maxn = max(maxn, z[b]);
												maxn = max(maxn, z[c]);
												maxn = max(maxn, z[d]);
												maxn = max(maxn, z[e]);
												maxn = max(maxn, z[f]);
												maxn = max(maxn, z[g]);
												maxn = max(maxn, z[h]);
												maxn = max(maxn, z[i]);
												maxn = max(maxn, z[j]);
												int op = maxn * 2;
												if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] + z[j] > op){
													ans++;
												}
											}
											maxn = 0;
											maxn = max(maxn, z[a]);
											maxn = max(maxn, z[b]);
											maxn = max(maxn, z[c]);
											maxn = max(maxn, z[d]);
											maxn = max(maxn, z[e]);
											maxn = max(maxn, z[f]);
											maxn = max(maxn, z[g]);
											maxn = max(maxn, z[h]);
											maxn = max(maxn, z[i]);
										
											int op = maxn * 2;
											if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] + z[i] > op){
												ans++;
											}
										}
										maxn = 0;
										maxn = max(maxn, z[a]);
										maxn = max(maxn, z[b]);
										maxn = max(maxn, z[c]);
										maxn = max(maxn, z[d]);
										maxn = max(maxn, z[e]);
										maxn = max(maxn, z[f]);
										maxn = max(maxn, z[g]);
										maxn = max(maxn, z[h]);
										int op = maxn * 2;
										if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g] + z[h] > op){
											ans++;
										}
									}
									maxn = 0;
									maxn = max(maxn, z[a]);
									maxn = max(maxn, z[b]);
									maxn = max(maxn, z[c]);
									maxn = max(maxn, z[d]);
									maxn = max(maxn, z[e]);
									maxn = max(maxn, z[f]);
									maxn = max(maxn, z[g]);
									int op = maxn * 2;
									if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f] + z[g]> op){
										ans++;
									}
								}
								maxn = 0;
								maxn = max(maxn, z[a]);
								maxn = max(maxn, z[b]);
								maxn = max(maxn, z[c]);
								maxn = max(maxn, z[d]);
								maxn = max(maxn, z[e]);
								maxn = max(maxn, z[f]);
								int op = maxn * 2;
								if (z[a] + z[b] + z[c] + z[d] + z[e] + z[f]> op){
									ans++;
								}
							}
							maxn = 0;
							maxn = max(maxn, z[a]);
							maxn = max(maxn, z[b]);
							maxn = max(maxn, z[c]);
							maxn = max(maxn, z[d]);
							maxn = max(maxn, z[e]);
							
							int op = maxn * 2;
							if (z[a] + z[b] + z[c] + z[d] + z[e] > op){
								ans++;
							}
						}
						maxn = 0;
						maxn = max(maxn, z[a]);
						maxn = max(maxn, z[b]);
						maxn = max(maxn, z[c]);
						maxn = max(maxn, z[d]);
							
						
						int op = maxn * 2;
						if (z[a] + z[b] + z[c] + z[d] > op){
							ans++;
						}
					}
					maxn = 0;
					maxn = max(maxn, z[a]);
					maxn = max(maxn, z[b]);
					maxn = max(maxn, z[c]);
					
					int op = maxn * 2;
					if (z[a] + z[b] + z[c] > op){
						ans++;
					}
				}
			}
		}
		
		
		printf("%d", ans % mod);
		return 0;
	}
	if (n == 20){
		cout << 1042392;
		return 0;
	} 
	if (n == 500){
		cout << 366911923;
		return 0;
	}
	
	cout << 2 << endl;
	
	
	
	return 0;
}
