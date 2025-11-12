#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 5e3 + 5;
int a[MAXN], cnt;
void solve3(int x, int y, int z) {
	if (x + y + z <= z * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve4(int x, int y, int z, int a) {
	if (x + y + z + a <= a * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve5(int x, int y, int z, int a, int b) {
	if (x + y + z + a + b <= b * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve6(int x, int y, int z, int a, int b, int c) {
	if (x + y + z + a + b + c <= c * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve7(int x, int y, int z, int a, int b, int c, int d) {
	if (x + y + z + a + b + c + d <= d * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve8(int x, int y, int z, int a, int b, int c, int d, int e) {
	if (x + y + z + a + b + c + d + e <= e * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve9(int x, int y, int z, int a, int b, int c, int d, int e, int f) {
	if (x + y + z + a + b + c + d + e + f <= f * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve10(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g) {
	if (x + y + z + a + b + c + d + e + f + g <= g * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve11(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h) {
	if (x + y + z + a + b + c + d + e + f + g + h <= h * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve12(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i) {
	if (x + y + z + a + b + c + d + e + f + g + h + i <= i * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve13(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
	if (x + y + z + a + b + c + d + e + f + g + h + i + j <= j * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve14(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
	if (x + y + z + a + b + c + d + e + f + g + h + i + j + k <= k * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve15(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
	if (x + y + z + a + b + c + d + e + f + g + h + i + j + k + l <= l * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve16(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m) {
	if (x + y + z + a + b + c + d + e + f + g + h + i + j + k + l + m <= m * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve17(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
	if (x + y + z + a + b + c + d + e + f + g + h + i + j + k + l + m + n <= n * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve18(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o) {
	if (x + y + z + a + b + c + d + e + f + g + h + i + j + k + l + m + n + o <= o * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve19(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
	if (x + y + z + a + b + c + d + e + f + g + h + i + j + k + l + m + n + p <= p * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
void solve20(int x, int y, int z, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q) {
	if (x + y + z + a + b + c + d + e + f + g + h + i + j + k + l + m + n + p + q <= q * 2) {
		return ;
	}
	else {
		cnt++; 
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	if (n <= 3) {
		cout << 0 << '\n';
		return 0;
	}
	if (n == 3) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
				}
			}
		}	
	}
	if (n == 4) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
					}
				}
			}
		}
	}
	if (n == 5) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
						}
					}
				}
			}
		}
	}
	if (n == 6) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
							}
						}
					}
				}
			}
		}
	}
	if (n == 7) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
								}
							}
						}
					}
				}
			}
		}
	}
	if (n == 8) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (n == 9) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
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
	if (n == 10) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
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
	if (n == 11) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
												for (int d1 = c1 + 1; d1 <= n; ++d1) {
													solve11(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1]);
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
	if (n == 12) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
												for (int d1 = c1 + 1; d1 <= n; ++d1) {
													solve11(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1]);
													for (int e1 = d1 + 1; e1 <= n; ++e1) {
														solve12(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1]);
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
	}
	if (n == 13) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
												for (int d1 = c1 + 1; d1 <= n; ++d1) {
													solve11(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1]);
													for (int e1 = d1 + 1; e1 <= n; ++e1) {
														solve12(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1]);
														for (int f1 = e1 + 1; f1 <= n; ++f1) {
															solve13(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1]);
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
		}
	}
	if (n == 14) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
												for (int d1 = c1 + 1; d1 <= n; ++d1) {
													solve11(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1]);
													for (int e1 = d1 + 1; e1 <= n; ++e1) {
														solve12(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1]);
														for (int f1 = e1 + 1; f1 <= n; ++f1) {
															solve13(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1]);
															for (int g1 = f1 + 1; g1 <= n; ++g1) {
																solve14(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1]);
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
			}
		}
	}
	if (n == 15) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
												for (int d1 = c1 + 1; d1 <= n; ++d1) {
													solve11(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1]);
													for (int e1 = d1 + 1; e1 <= n; ++e1) {
														solve12(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1]);
														for (int f1 = e1 + 1; f1 <= n; ++f1) {
															solve13(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1]);
															for (int g1 = f1 + 1; g1 <= n; ++g1) {
																solve14(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1]);
																for (int h1 = g1 + 1; h1 <= n; ++h1) {
																	solve15(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1]);
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
				}
			}
		}
	}
	if (n == 16) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
												for (int d1 = c1 + 1; d1 <= n; ++d1) {
													solve11(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1]);
													for (int e1 = d1 + 1; e1 <= n; ++e1) {
														solve12(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1]);
														for (int f1 = e1 + 1; f1 <= n; ++f1) {
															solve13(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1]);
															for (int g1 = f1 + 1; g1 <= n; ++g1) {
																solve14(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1]);
																for (int h1 = g1 + 1; h1 <= n; ++h1) {
																	solve15(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1]);
																	for (int l1 = h1 + 1; l1 <= n; ++l1) {
																		solve16(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1]);
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
					}
				}
			}
		}
	}
	if (n == 17) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
												for (int d1 = c1 + 1; d1 <= n; ++d1) {
													solve11(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1]);
													for (int e1 = d1 + 1; e1 <= n; ++e1) {
														solve12(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1]);
														for (int f1 = e1 + 1; f1 <= n; ++f1) {
															solve13(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1]);
															for (int g1 = f1 + 1; g1 <= n; ++g1) {
																solve14(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1]);
																for (int h1 = g1 + 1; h1 <= n; ++h1) {
																	solve15(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1]);
																	for (int l1 = h1 + 1; l1 <= n; ++l1) {
																		solve16(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1]);
																		for (int m1 = l1 + 1; m1 <= n; ++m1) {
																			solve17(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1], a[m1]);
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
						}
					}
				}
			}
		}
	}
	if (n == 18) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
												for (int d1 = c1 + 1; d1 <= n; ++d1) {
													solve11(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1]);
													for (int e1 = d1 + 1; e1 <= n; ++e1) {
														solve12(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1]);
														for (int f1 = e1 + 1; f1 <= n; ++f1) {
															solve13(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1]);
															for (int g1 = f1 + 1; g1 <= n; ++g1) {
																solve14(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1]);
																for (int h1 = g1 + 1; h1 <= n; ++h1) {
																	solve15(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1]);
																	for (int l1 = h1 + 1; l1 <= n; ++l1) {
																		solve16(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1]);
																		for (int m1 = l1 + 1; m1 <= n; ++m1) {
																			solve17(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1], a[m1]);
																			for (int n1 = m1 + 1; n1 <= n; ++n1) {
																				solve18(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1], a[m1], a[n1]);
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
							}
						}
					}
				}
			}
		}
	}
	if (n == 19) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
												for (int d1 = c1 + 1; d1 <= n; ++d1) {
													solve11(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1]);
													for (int e1 = d1 + 1; e1 <= n; ++e1) {
														solve12(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1]);
														for (int f1 = e1 + 1; f1 <= n; ++f1) {
															solve13(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1]);
															for (int g1 = f1 + 1; g1 <= n; ++g1) {
																solve14(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1]);
																for (int h1 = g1 + 1; h1 <= n; ++h1) {
																	solve15(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1]);
																	for (int l1 = h1 + 1; l1 <= n; ++l1) {
																		solve16(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1]);
																		for (int m1 = l1 + 1; m1 <= n; ++m1) {
																			solve17(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1], a[m1]);
																			for (int n1 = m1 + 1; n1 <= n; ++n1) {
																				solve18(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1], a[m1], a[n1]);
																				for (int o1 = n1 + 1; o1 <= n; ++o1) {
																					solve19(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1], a[m1], a[n1], a[o1]);
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
								}
							}
						}
					}
				}
			}
		}
	}
	if (n == 20) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = j + 1; k <= n; ++k) {
					solve3(a[i], a[j], a[k]);
					for (int i1 = k + 1; i1 <= n; ++i1) {
						solve4(a[i], a[j], a[k], a[i1]);
						for (int j1 = i1 + 1; j1 <= n; ++j1) {
							solve5(a[i], a[j], a[k], a[i1], a[j1]);
							for (int k1 = j1 + 1; k1 <= n; ++k1) {
								solve6(a[i], a[j], a[k], a[i1], a[j1], a[k1]);
								for (int s1 = k1 + 1; s1 <= n; ++s1) {
									solve7(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1]);
									for (int a1 = s1 + 1; a1 <= n; ++a1) {
										solve8(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1]);
										for (int b1 = a1 + 1; b1 <= n; ++ b1) {
											solve9(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1]);
											for (int c1 = b1 + 1; c1 <= n; ++c1) {
												solve10(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1]);
												for (int d1 = c1 + 1; d1 <= n; ++d1) {
													solve11(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1]);
													for (int e1 = d1 + 1; e1 <= n; ++e1) {
														solve12(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1]);
														for (int f1 = e1 + 1; f1 <= n; ++f1) {
															solve13(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1]);
															for (int g1 = f1 + 1; g1 <= n; ++g1) {
																solve14(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1]);
																for (int h1 = g1 + 1; h1 <= n; ++h1) {
																	solve15(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1]);
																	for (int l1 = h1 + 1; l1 <= n; ++l1) {
																		solve16(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1]);
																		for (int m1 = l1 + 1; m1 <= n; ++m1) {
																			solve17(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1], a[m1]);
																			for (int n1 = m1 + 1; n1 <= n; ++n1) {
																				solve18(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1], a[m1], a[n1]);
																				for (int o1 = n1 + 1; o1 <= n; ++o1) {
																					solve19(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1], a[m1], a[n1], a[o1]);
																					for (int p1 = o1 + 1; p1 <= n; ++p1) {
																						solve20(a[i], a[j], a[k], a[i1], a[j1], a[k1], a[s1], a[a1], a[b1], a[c1], a[d1], a[e1], a[f1], a[g1], a[h1], a[l1], a[m1], a[n1], a[o1], a[p1]);
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
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << cnt % MOD << '\n';
	return 0;
}
