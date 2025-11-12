#include <bits/stdc++.h>
using namespace std;
int a[100010];
int k[100010];
int n, ans = 0;
int find1() {
	int num = 0;
	for (k[1] = 1; k[1] <= n; ++k[1]) {
		for (k[2] = k[1] + 1; k[2] <= n; ++k[2]) {
			for (k[3] = k[2] + 1; k[3] <= n; ++k[3]) {
				int maxk = -1, cntk = 0;
				for (int i = 1; i <= 3; ++i){maxk = max(maxk, a[k[i]]);cntk += a[k[i]];}
				if (cntk > maxk * 2) ++num;
			}
		}
	}
	return num;
}
int find2() {
	int num = 0;
	for (k[1] = 1; k[1] <= n; ++k[1]) {
		for (k[2] = k[1] + 1; k[2] <= n; ++k[2]) {
			for (k[3] = k[2] + 1; k[3] <= n; ++k[3]) {
				for (k[4] = k[3] + 1; k[4] <= n; ++k[4]) {
					int maxk = -1, cntk = 0;
					for (int i = 1; i <= 4; ++i){maxk = max(maxk, a[k[i]]);cntk += a[k[i]];}
					if (cntk > maxk * 2) ++num;
				}
				
			}
		}
	}
	return num;
}
int find3() {
	int num = 0;
	for (k[1] = 1; k[1] <= n; ++k[1]) {
		for (k[2] = k[1] + 1; k[2] <= n; ++k[2]) {
			for (k[3] = k[2] + 1; k[3] <= n; ++k[3]) {
				for (k[4] = k[3] + 1; k[4] <= n; ++k[4]) {
					for (k[5] = k[4] + 1; k[5] <= n; ++k[5]) {
						int maxk = -1, cntk = 0;
						for (int i = 1; i <= 5; ++i){maxk = max(maxk, a[k[i]]);cntk += a[k[i]];}
						if (cntk > maxk * 2) ++num;
					}
				}
				
			}
		}
	}
	return num;
}
int find4() {
	int num = 0;
	for (k[1] = 1; k[1] <= n; ++k[1]) {
		for (k[2] = k[1] + 1; k[2] <= n; ++k[2]) {
			for (k[3] = k[2] + 1; k[3] <= n; ++k[3]) {
				for (k[4] = k[3] + 1; k[4] <= n; ++k[4]) {
					for (k[5] = k[4] + 1; k[5] <= n; ++k[5]) {
						for (k[6] = k[5] + 1; k[6] <= n; ++k[6]) {
							int maxk = -1, cntk = 0;
							for (int i = 1; i <= 6; ++i){maxk = max(maxk, a[k[i]]);cntk += a[k[i]];}
							if (cntk > maxk * 2) ++num;
						}
					}
				}
				
			}
		}
	}
	return num;
}
int find5() {
	int num = 0;
	for (k[1] = 1; k[1] <= n; ++k[1]) {
		for (k[2] = k[1] + 1; k[2] <= n; ++k[2]) {
			for (k[3] = k[2] + 1; k[3] <= n; ++k[3]) {
				for (k[4] = k[3] + 1; k[4] <= n; ++k[4]) {
					for (k[5] = k[4] + 1; k[5] <= n; ++k[5]) {
						for (k[6] = k[5] + 1; k[6] <= n; ++k[6]) {
							for (k[7] = k[6] + 1; k[7] <= n; ++k[7]) {
								int maxk = -1, cntk = 0;
								for (int i = 1; i <= 7; ++i){maxk = max(maxk, a[k[i]]);cntk += a[k[i]];}
								if (cntk > maxk * 2) ++num;
							}
						}
					}
				}
				
			}
		}
	}
	return num;
}
int find6() {
	int num = 0;
	for (k[1] = 1; k[1] <= n; ++k[1]) {
		for (k[2] = k[1] + 1; k[2] <= n; ++k[2]) {
			for (k[3] = k[2] + 1; k[3] <= n; ++k[3]) {
				for (k[4] = k[3] + 1; k[4] <= n; ++k[4]) {
					for (k[5] = k[4] + 1; k[5] <= n; ++k[5]) {
						for (k[6] = k[5] + 1; k[6] <= n; ++k[6]) {
							for (k[7] = k[6] + 1; k[7] <= n; ++k[7]) {
								for (k[8] = k[7] + 1; k[8] <= n; ++k[8]) {
									int maxk = -1, cntk = 0;
									for (int i = 1; i <= 8; ++i){maxk = max(maxk, a[k[i]]);cntk += a[k[i]];}
									if (cntk > maxk * 2) ++num;
								}
								
							}
						}
					}
				}
				
			}
		}
	}
	return num;
}
int find7() {
	int num = 0;
	for (k[1] = 1; k[1] <= n; ++k[1]) {
		for (k[2] = k[1] + 1; k[2] <= n; ++k[2]) {
			for (k[3] = k[2] + 1; k[3] <= n; ++k[3]) {
				for (k[4] = k[3] + 1; k[4] <= n; ++k[4]) {
					for (k[5] = k[4] + 1; k[5] <= n; ++k[5]) {
						for (k[6] = k[5] + 1; k[6] <= n; ++k[6]) {
							for (k[7] = k[6] + 1; k[7] <= n; ++k[7]) {
								for (k[8] = k[7] + 1; k[8] <= n; ++k[8]) {
									for (k[9] = k[8] + 1; k[9] <= n; ++k[9]) {
										int maxk = -1, cntk = 0;
										for (int i = 1; i <= 9; ++i){maxk = max(maxk, a[k[i]]);cntk += a[k[i]];}
										if (cntk > maxk * 2) ++num;
									}
								}
							}
						}
					}
				}
				
			}
		}
	}
	return num;
}
int find8() {
	int num = 0;
	for (k[1] = 1; k[1] <= n; ++k[1]) {
		for (k[2] = k[1] + 1; k[2] <= n; ++k[2]) {
			for (k[3] = k[2] + 1; k[3] <= n; ++k[3]) {
				for (k[4] = k[3] + 1; k[4] <= n; ++k[4]) {
					for (k[5] = k[4] + 1; k[5] <= n; ++k[5]) {
						for (k[6] = k[5] + 1; k[6] <= n; ++k[6]) {
							for (k[7] = k[6] + 1; k[7] <= n; ++k[7]) {
								for (k[8] = k[7] + 1; k[8] <= n; ++k[8]) {
									for (k[9] = k[8] + 1; k[9] <= n; ++k[9]) {
										for (k[10] = k[9] + 1; k[10] <= n; ++k[10]) {
											int maxk = -1, cntk = 0;
											for (int i = 1; i <= 10; ++i){maxk = max(maxk, a[k[i]]);cntk += a[k[i]];}
											if (cntk > maxk * 2) ++num;
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
	return num;
}
int find9() {
	int num = 0;
	for (k[1] = 1; k[1] <= n; ++k[1]) {
		for (k[2] = k[1] + 1; k[2] <= n; ++k[2]) {
			for (k[3] = k[2] + 1; k[3] <= n; ++k[3]) {
				for (k[4] = k[3] + 1; k[4] <= n; ++k[4]) {
					for (k[5] = k[4] + 1; k[5] <= n; ++k[5]) {
						for (k[6] = k[5] + 1; k[6] <= n; ++k[6]) {
							for (k[7] = k[6] + 1; k[7] <= n; ++k[7]) {
								for (k[8] = k[7] + 1; k[8] <= n; ++k[8]) {
									for (k[9] = k[8] + 1; k[9] <= n; ++k[9]) {
										for (k[10] = k[9] + 1; k[10] <= n; ++k[10]) {
											for (k[11] = k[10] + 1; k[11] <= n; ++k[11]) {
												int maxk = -1, cntk = 0;
												for (int i = 1; i <= 11; ++i){maxk = max(maxk, a[k[i]]);cntk += a[k[i]];}
												if (cntk > maxk * 2) ++num;
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
	return num;
}
int find10() {
	int num = 0;
	for (k[1] = 1; k[1] <= n; ++k[1]) {
		for (k[2] = k[1] + 1; k[2] <= n; ++k[2]) {
			for (k[3] = k[2] + 1; k[3] <= n; ++k[3]) {
				for (k[4] = k[3] + 1; k[4] <= n; ++k[4]) {
					for (k[5] = k[4] + 1; k[5] <= n; ++k[5]) {
						for (k[6] = k[5] + 1; k[6] <= n; ++k[6]) {
							for (k[7] = k[6] + 1; k[7] <= n; ++k[7]) {
								for (k[8] = k[7] + 1; k[8] <= n; ++k[8]) {
									for (k[9] = k[8] + 1; k[9] <= n; ++k[9]) {
										for (k[10] = k[9] + 1; k[10] <= n; ++k[10]) {
											for (k[11] = k[10] + 1; k[11] <= n; ++k[11]) {
												for (k[12] = k[11] + 1; k[12] <= n; ++k[12]) {
													int maxk = -1, cntk = 0;
													for (int i = 1; i <= 12; ++i){maxk = max(maxk, a[k[i]]);cntk += a[k[i]];}
													if (cntk > maxk * 2) ++num;
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
	}
	return num;
}
int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n == 1 || n == 2) {
		cout << 0;
	}
	else if (n == 3) {
		ans += find1();
		cout << ans;
	}
	else if (n == 4) {
		ans += find1();
		for (int i = 1; i <= 3; ++i) k[i] = 0;
		ans += find2();
		cout << ans;
	}
	else if (n == 5) {
		ans += find1();
		for (int i = 1; i <= 3; ++i) k[i] = 0;
		ans += find2();
		for (int i = 1; i <= 4; ++i) k[i] = 0;
		ans += find3();
		cout << ans;
	}
	else if (n == 6) {
		ans += find1();
		for (int i = 1; i <= 3; ++i) k[i] = 0;
		ans += find2();
		for (int i = 1; i <= 4; ++i) k[i] = 0;
		ans += find3();
		for (int i = 1; i <= 5; ++i) k[i] = 0;
		ans += find4();
		cout << ans;
	}
	else if (n == 7) {
		ans += find1();
		for (int i = 1; i <= 3; ++i) k[i] = 0;
		ans += find2();
		for (int i = 1; i <= 4; ++i) k[i] = 0;
		ans += find3();
		for (int i = 1; i <= 5; ++i) k[i] = 0;
		ans += find4();
		for (int i = 1; i <= 6; ++i) k[i] = 0;
		ans += find5();
		cout << ans;
	}
	else if (n == 8) {
		ans += find1();
		for (int i = 1; i <= 3; ++i) k[i] = 0;
		ans += find2();
		for (int i = 1; i <= 4; ++i) k[i] = 0;
		ans += find3();
		for (int i = 1; i <= 5; ++i) k[i] = 0;
		ans += find4();
		for (int i = 1; i <= 6; ++i) k[i] = 0;
		ans += find5();
		for (int i = 1; i <= 7; ++i) k[i] = 0;
		ans += find6();
		cout << ans;
	}
	else if (n == 9) {
		ans += find1();
		for (int i = 1; i <= 3; ++i) k[i] = 0;
		ans += find2();
		for (int i = 1; i <= 4; ++i) k[i] = 0;
		ans += find3();
		for (int i = 1; i <= 5; ++i) k[i] = 0;
		ans += find4();
		for (int i = 1; i <= 6; ++i) k[i] = 0;
		ans += find5();
		for (int i = 1; i <= 7; ++i) k[i] = 0;
		ans += find6();
		for (int i = 1; i <= 8; ++i) k[i] = 0;
		ans += find7();
		cout << ans;
	}
	else if (n == 10) {
		ans += find1();
		for (int i = 1; i <= 3; ++i) k[i] = 0;
		ans += find2();
		for (int i = 1; i <= 4; ++i) k[i] = 0;
		ans += find3();
		for (int i = 1; i <= 5; ++i) k[i] = 0;
		ans += find4();
		for (int i = 1; i <= 6; ++i) k[i] = 0;
		ans += find5();
		for (int i = 1; i <= 7; ++i) k[i] = 0;
		ans += find6();
		for (int i = 1; i <= 8; ++i) k[i] = 0;
		ans += find7();
		for (int i = 1; i <= 9; ++i) k[i] = 0;
		ans += find8();
		cout << ans;
	}
	else if (n == 11) {
		ans += find1();
		for (int i = 1; i <= 3; ++i) k[i] = 0;
		ans += find2();
		for (int i = 1; i <= 4; ++i) k[i] = 0;
		ans += find3();
		for (int i = 1; i <= 5; ++i) k[i] = 0;
		ans += find4();
		for (int i = 1; i <= 6; ++i) k[i] = 0;
		ans += find5();
		for (int i = 1; i <= 7; ++i) k[i] = 0;
		ans += find6();
		for (int i = 1; i <= 8; ++i) k[i] = 0;
		ans += find7();
		for (int i = 1; i <= 9; ++i) k[i] = 0;
		ans += find8();
		for (int i = 1; i <= 10; ++i) k[i] = 0;
		ans += find9();
		cout << ans;
	}
	else if (n == 12) {
		ans += find1();
		for (int i = 1; i <= 3; ++i) k[i] = 0;
		ans += find2();
		for (int i = 1; i <= 4; ++i) k[i] = 0;
		ans += find3();
		for (int i = 1; i <= 5; ++i) k[i] = 0;
		ans += find4();
		for (int i = 1; i <= 6; ++i) k[i] = 0;
		ans += find5();
		for (int i = 1; i <= 7; ++i) k[i] = 0;
		ans += find6();
		for (int i = 1; i <= 8; ++i) k[i] = 0;
		ans += find7();
		for (int i = 1; i <= 9; ++i) k[i] = 0;
		ans += find8();
		for (int i = 1; i <= 10; ++i) k[i] = 0;
		ans += find9();
		for (int i = 1; i <= 11; ++i) k[i] = 0;
		ans += find10();
		cout << ans;
	}
	return 0;
}