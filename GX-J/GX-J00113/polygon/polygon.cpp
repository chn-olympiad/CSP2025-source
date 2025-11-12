#include<iostream>
#include<algorithm>
using namespace std ;

int n ;
int a[10010] ;

int main() {
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	cin >> n ;
	for( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
	}
	sort(a+1,a+n+1) ;
	if( n == 3 ) {
		if( a[1] + a[2] > a[3] ) {
			cout << 1 << endl ;
		} else {
			cout << 0 << endl ;
		}
	}
	int cnt = 0 ;
	if( n == 4 ) {
		for( int i = 1 ; i <= 2 ; i ++ ) {
			for( int j = i + 1 ; j <= 3 ; j ++ ) {
				for( int k = j + 1 ; k <= 4 ; k ++ ) {
					if( a[i] + a[j] > a[k] ) {
						cnt ++ ;
					}
				}
			}
		}
		if( a[1] + a[2] + a[3] + a[4] > a[4] * 2 ) {
			cnt ++ ;
		}
		cout << cnt << endl ;
	}
	if( n == 5 ) {
		for( int i = 1 ; i <= 3 ; i ++ ) {
			for( int j = i + 1 ; j <= 4 ; j ++ ) {
				for( int k = j + 1 ; k <= 5 ; k ++ ) {
					if( a[i] + a[j] > a[k] ) {
						cnt ++ ;
					}
				}
			}
		}
		for( int i = 1 ; i <= 2 ; i ++ ) {
			for( int j = i + 1 ; j <= 3 ; j ++ ) {
				for( int k = j + 1 ; k <= 4 ; k ++ ) {
					for( int u = k + 1 ; u <= 5 ; u ++ ) {
						if( a[i] + a[j] + a[k] + a[u] > a[u] * 2 ) {
							cnt ++ ;
						}
					}
				}
			}
		}
		if( a[1] + a[2] + a[3] + a[4] + a[5] > a[5] * 2 ) {
			cnt ++ ;
		}
		cout << cnt << endl ;
	}
	if( n == 6 ) {
		for( int i = 1 ; i <= 4 ; i ++ ) {
			for( int j = i + 1 ; j <= 5 ; j ++ ) {
				for( int k = j + 1 ; k <= 6 ; k ++ ) {
					if( a[i] + a[j] > a[k] ) {
						cnt ++ ;
					}
				}
			}
		}
		for( int i = 1 ; i <= 3 ; i ++ ) {
			for( int j = i + 1 ; j <= 4 ; j ++ ) {
				for( int k = j + 1 ; k <= 5 ; k ++ ) {
					for( int u = k + 1 ; u <= 6 ; u ++ ) {
						if( a[i] + a[j] + a[k] + a[u] > a[u] * 2 ) {
							cnt ++ ;
						}
					}
				}
			}
		}
		for( int i = 1 ; i <= 2 ; i ++ ) {
			for( int j = i + 1 ; j <= 3 ; j ++ ) {
				for( int k = j + 1 ; k <= 4 ; k ++ ) {
					for( int u = k + 1 ; u <= 5 ; u ++ ) {
						for( int v = u + 1 ; v <= 6 ; v ++ ) {
							if( a[i] + a[j] + a[k] + a[u] + a[v] > a[v] * 2 ) {
								cnt ++ ;
							}
						}
					}
				}
			}
		}
		if( a[1] + a[2] + a[3] + a[4] + a[5] + a[6] > a[6] * 2 ) {
			cnt ++ ;
		}
		cout << cnt << endl ;
	}
	if( n == 7 ) {
		for( int i = 1 ; i <= 5 ; i ++ ) {
			for( int j = i + 1 ; j <= 6 ; j ++ ) {
				for( int k = j + 1 ; k <= 7 ; k ++ ) {
					if( a[i] + a[j] > a[k] ) {
						cnt ++ ;
					}
				}
			}
		}
		for( int i = 1 ; i <= 4 ; i ++ ) {
			for( int j = i + 1 ; j <= 5 ; j ++ ) {
				for( int k = j + 1 ; k <= 6 ; k ++ ) {
					for( int u = k + 1 ; u <= 7 ; u ++ ) {
						if( a[i] + a[j] + a[k] + a[u] > a[u] * 2 ) {
							cnt ++ ;
						}
					}
				}
			}
		}
		for( int i = 1 ; i <= 3 ; i ++ ) {
			for( int j = i + 1 ; j <= 4 ; j ++ ) {
				for( int k = j + 1 ; k <= 5 ; k ++ ) {
					for( int u = k + 1 ; u <= 6 ; u ++ ) {
						for( int v = u + 1 ; v <= 7 ; v ++ ) {
							if( a[i] + a[j] + a[k] + a[u] + a[v] > a[v] * 2 ) {
								cnt ++ ;
							}
						}
					}
				}
			}
		}
		for( int i = 1 ; i <= 2 ; i ++ ) {
			for( int j = i + 1 ; j <= 3 ; j ++ ) {
				for( int k = j + 1 ; k <= 4 ; k ++ ) {
					for( int u = k + 1 ; u <= 5 ; u ++ ) {
						for( int v = u + 1 ; v <= 6 ; v ++ ) {
							for( int x = v + 1 ; x <= 7 ; x ++ ) {
								if( a[i] + a[j] + a[k] + a[u] + a[v] + a[x] > a[x] * 2 ) {
									cnt ++ ;
								}
							}
						}
					}
				}
			}
		}
		if( a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] > a[7] * 2 ) {
			cnt ++ ;
		}
		cout << cnt << endl ;
	}
	if( n == 8 ) {
		for( int i = 1 ; i <= 6 ; i ++ ) {
			for( int j = i + 1 ; j <= 7 ; j ++ ) {
				for( int k = j + 1 ; k <= 8 ; k ++ ) {
					if( a[i] + a[j] > a[k] ) {
						cnt ++ ;
					}
				}
			}
		}
		for( int i = 1 ; i <= 5 ; i ++ ) {
			for( int j = i + 1 ; j <= 6 ; j ++ ) {
				for( int k = j + 1 ; k <= 7 ; k ++ ) {
					for( int u = k + 1 ; u <= 8 ; u ++ ) {
						if( a[i] + a[j] + a[k] + a[u] > a[u] * 2 ) {
							cnt ++ ;
						}
					}
				}
			}
		}
		for( int i = 1 ; i <= 4 ; i ++ ) {
			for( int j = i + 1 ; j <= 5 ; j ++ ) {
				for( int k = j + 1 ; k <= 6 ; k ++ ) {
					for( int u = k + 1 ; u <= 7 ; u ++ ) {
						for( int v = u + 1 ; v <= 8 ; v ++ ) {
							if( a[i] + a[j] + a[k] + a[u] + a[v] > a[v] * 2 ) {
								cnt ++ ;
							}
						}
					}
				}
			}
		}
		for( int i = 1 ; i <= 3 ; i ++ ) {
			for( int j = i + 1 ; j <= 4 ; j ++ ) {
				for( int k = j + 1 ; k <= 5 ; k ++ ) {
					for( int u = k + 1 ; u <= 6 ; u ++ ) {
						for( int v = u + 1 ; v <= 7 ; v ++ ) {
							for( int x = v + 1 ; x <= 8 ; x ++ ) {
								if( a[i] + a[j] + a[k] + a[u] + a[v] + a[x] > a[x] * 2 ) {
									cnt ++ ;
								}
							}
						}
					}
				}
			}
		}
		for( int i = 1 ; i <= 2 ; i ++ ) {
			for( int j = i + 1 ; j <= 3 ; j ++ ) {
				for( int k = j + 1 ; k <= 4 ; k ++ ) {
					for( int u = k + 1 ; u <= 5 ; u ++ ) {
						for( int v = u + 1 ; v <= 6 ; v ++ ) {
							for( int x = v + 1 ; x <= 7 ; x ++ ) {
								for( int y = x + 1 ; y <= 8 ; y ++ ) {
									if( a[i] + a[j] + a[k] + a[u] + a[v] + a[x] + a[y] > a[y] * 2 ) {
										cnt ++ ;
									}
								}
							}
						}
					}
				}
			}
		}

		if( a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] > a[8] * 2 ) {
			cnt ++ ;
		}
		cout << cnt << endl ;
	}
	return 0 ;
}
