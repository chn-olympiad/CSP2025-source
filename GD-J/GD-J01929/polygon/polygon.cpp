#include<bits/stdc++.h>
using namespace std;
int a[5007];
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n ;i++){
		cin >> a[i];
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	int b[12];
	int ans = 0;
	if(n == 10){
	
	for( b[1] = 1;b[1] <= 2; b[1]++){
		for(b[2] = 1;b[2] <= 2; b[2]++){
			for( b[3] = 1;b[3] <= 2; b[3]++){
				for( b[4] = 1;b[4] <= 2; b[4]++){
					for( b[5] = 1;b[5] <= 2; b[5]++){
						for(b[6] = 1;b[6] <= 2; b[6]++){
							for( b[7] = 1;b[7] <= 2; b[7]++){
								for(b[8] = 1;b[8] <= 2; b[8]++){
									for( b[9] = 1;b[9] <= 2; b[9]++){
										for( b[10] = 1;b[10] <= 2; b[10]++){
											int cnt = 0;
											int sum = 0;
											int maxx = a[1];
											for(int i = 1;i <= n; i++){
												if(b[i] == 2)sum++;
												if(b[i] == 2)cnt += a[i];
												if(b[i] == 2 && a[i] > maxx)maxx = a[i];
											}
											if(sum >=3 && cnt/2 > maxx)ans++;
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
else 	if(n == 9){
	
	for( b[1] = 1;b[1] <= 2; b[1]++){
		for(b[2] = 1;b[2] <= 2; b[2]++){
			for( b[3] = 1;b[3] <= 2; b[3]++){
				for( b[4] = 1;b[4] <= 2; b[4]++){
					for( b[5] = 1;b[5] <= 2; b[5]++){
						for(b[6] = 1;b[6] <= 2; b[6]++){
							for( b[7] = 1;b[7] <= 2; b[7]++){
								for(b[8] = 1;b[8] <= 2; b[8]++){
									for( b[9] = 1;b[9] <= 2; b[9]++){
										
											int cnt = 0;
											int sum = 0;
											int maxx = a[1];
											for(int i = 1;i <= n; i++){
												if(b[i] == 2)sum++;
												if(b[i] == 2)cnt += a[i];
												if(b[i] == 2 && a[i] > maxx)maxx = a[i];
											}
											if(sum >=3 && cnt/2 > maxx)ans++;
										
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
else 	if(n == 8){
	
	for( b[1] = 1;b[1] <= 2; b[1]++){
		for(b[2] = 1;b[2] <= 2; b[2]++){
			for( b[3] = 1;b[3] <= 2; b[3]++){
				for( b[4] = 1;b[4] <= 2; b[4]++){
					for( b[5] = 1;b[5] <= 2; b[5]++){
						for(b[6] = 1;b[6] <= 2; b[6]++){
							for( b[7] = 1;b[7] <= 2; b[7]++){
								for(b[8] = 1;b[8] <= 2; b[8]++){
					
										
											int cnt = 0;
											int sum = 0;
											int maxx = a[1];
											for(int i = 1;i <= n; i++){
												if(b[i] == 2)sum++;
												if(b[i] == 2)cnt += a[i];
												if(b[i] == 2 && a[i] > maxx)maxx = a[i];
											}
											if(sum >=3 && cnt/2 > maxx)ans++;
										
									
								}
							}
						}
					}
				}
			}	
		}
	}
}
else 	if(n == 7){
	
	for( b[1] = 1;b[1] <= 2; b[1]++){
		for(b[2] = 1;b[2] <= 2; b[2]++){
			for( b[3] = 1;b[3] <= 2; b[3]++){
				for( b[4] = 1;b[4] <= 2; b[4]++){
					for( b[5] = 1;b[5] <= 2; b[5]++){
						for(b[6] = 1;b[6] <= 2; b[6]++){
							for( b[7] = 1;b[7] <= 2; b[7]++){
							
										
											int cnt = 0;
											int sum = 0;
											int maxx = a[1];
											for(int i = 1;i <= n; i++){
												if(b[i] == 2)sum++;
												if(b[i] == 2)cnt += a[i];
												if(b[i] == 2 && a[i] > maxx)maxx = a[i];
											}
											if(sum >=3 && cnt/2 > maxx)ans++;
										
									
								
							}
						}
					}
				}
			}	
		}
	}
}
else 	if(n == 6){
	
	for( b[1] = 1;b[1] <= 2; b[1]++){
		for(b[2] = 1;b[2] <= 2; b[2]++){
			for( b[3] = 1;b[3] <= 2; b[3]++){
				for( b[4] = 1;b[4] <= 2; b[4]++){
					for( b[5] = 1;b[5] <= 2; b[5]++){
						for(b[6] = 1;b[6] <= 2; b[6]++){
						
							
										
											int cnt = 0;
											int sum = 0;
											int maxx = a[1];
											for(int i = 1;i <= n; i++){
												if(b[i] == 2)sum++;
												if(b[i] == 2)cnt += a[i];
												if(b[i] == 2 && a[i] > maxx)maxx = a[i];
											}
											if(sum >=3 && cnt/2 > maxx)ans++;
										
									
								
							
						}
					}
				}
			}	
		}
	}
}
else 	if(n == 5){
	
	for( b[1] = 1;b[1] <= 2; b[1]++){
		for(b[2] = 1;b[2] <= 2; b[2]++){
			for( b[3] = 1;b[3] <= 2; b[3]++){
				for( b[4] = 1;b[4] <= 2; b[4]++){
					for( b[5] = 1;b[5] <= 2; b[5]++){
					
						
							
										
											int cnt = 0;
											int sum = 0;
											int maxx = a[1];
											for(int i = 1;i <= n; i++){
												if(b[i] == 2)sum++;
												if(b[i] == 2)cnt += a[i];
												if(b[i] == 2 && a[i] > maxx)maxx = a[i];
											}
											if(sum >=3 && cnt/2 > maxx)ans++;
											cout << maxx <<' ' <<cnt << endl;
								
							
						
					}
				}
			}	
		}
	}
}
else 	if(n == 4){
	
	for( b[1] = 1;b[1] <= 2; b[1]++){
		for(b[2] = 1;b[2] <= 2; b[2]++){
			for( b[3] = 1;b[3] <= 2; b[3]++){
				for( b[4] = 1;b[4] <= 2; b[4]++){
						int cnt = 0;
											int sum = 0;
											int maxx = a[1];
											for(int i = 1;i <= n; i++){
												if(b[i] == 2)sum++;
												if(b[i] == 2)cnt += a[i];
												if(b[i] == 2 && a[i] > maxx)maxx = a[i];
											}
											if(sum >=3 && cnt/2 > maxx)ans++;
										
									
								
							
						
					
				}
			}	
		}
	}
}
else 	if(n == 4){
	
	for( b[1] = 1;b[1] <= 2; b[1]++){
		for(b[2] = 1;b[2] <= 2; b[2]++){
			for( b[3] = 1;b[3] <= 2; b[3]++){
			
						int cnt = 0;
											int sum = 0;
											int maxx = a[1];
											for(int i = 1;i <= n; i++){
												if(b[i] == 2)sum++;
												if(b[i] == 2)cnt += a[i];
												if(b[i] == 2 && a[i] > maxx)maxx = a[i];
											}
											if(sum >=3 && cnt/2 > maxx)ans++;
										
									
								
							
						
					
				
			}	
		}
	}
}
	cout << ans; 
}
