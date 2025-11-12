#include <bits/stdc++.h>
using namespace std;
int first(int a,int b,int c){
	if(a >= b and a >= c){
	    return a;
	}
	if(b >= a and b >= c){
		return b;
	}
	if(c >= a and c >= b){
		return c;
	}
	return 0;
}
int second(int a,int b,int c){
	if(a <= b and a >= c){
	    return a;
	}
	if(a <= c and a >= b){
	    return a;
	}
	if(b <= a and b >= c){
		return b;
	}
	if(b <= c and b >= a){
		return b;
	}
	if(c <= a and c >= b){
		return c;
	}
	if(c <= b and c >= a){
		return c;
	}
	return 0;
}
int third(int a,int b,int c){
	if(a <= b and a <= c){
	    return a;
	}
	if(b <= a and b <= c){
		return b;
	}
	if(c <= a and c <= b){
		return c;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a[100000][2],t,q[100000],w[100000],e[100000],j = 0,k = 0,l = 0,z;
	cin >> t;
	q[100000] = 0;
	w[100000] = 0;
	e[100000] = 0;
	for (int i = 0;i < 100000;i ++){
		q[i] = -1;
		w[i] = -1;
		e[i] = -1;
	}
	for (int p =0;p < t;p ++){
		cin >> n;
		for (int i = 0;i < n;i ++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		for (int i = 0;i < n;i ++){
		
			for (int b = 0;b < n;b ++){
				while (b <= q[i]){
					b++;
				}
				if(a[q[100000]][0]  < a[b][0]){
					q[100000] ++;
					b = 0;
				}
			}
			q[i] = q[100000];
			q[100000] = 0;
		}
		for (int i = 0;i < n;i ++){
		
			for (int b = 0;b < n;b ++){
				while (b <= w[i]){
					b++;
				}
				if(a[w[100000]][1]  < a[b][1]){
					w[100000] ++;
					b = 0;
				}
			}
			w[i] = w[100000];
			w[100000] = 0;
		}
		for (int i = 0;i < n;i ++){
		
			for (int b = 0;b < n;b ++){
				while (b <= e[i]){
					b++;
				}
				if(a[e[100000]][2]  < a[b][2]){
					e[100000] ++;
					b = 0;
				}
			}
			e[i] = e[100000];
			e[100000] = 0;
		}
		for (int i =0;i < n;i ++){
			if(j < n / 2 and k < n / 2){
				if(l < n / 2){
					z += first(q[i],w[i],e[i]);
					if(first(q[i],w[i],e[i]) == q[i]){
						j ++;
					}
					if (first(q[i],w[i],e[i]) == w[i]){
						k ++;
					}
					if (first(q[i],w[i],e[i]) == e[i]){
						l ++;
					}
				}
			}
			if(j < n / 2 and k < n / 2){
				if(l >= n / 2){
					
					if(first(q[i],w[i],e[i]) == q[i]){
						j ++;z += first(q[i],w[i],e[i]);
					}
					if (first(q[i],w[i],e[i]) == w[i]){
						k ++;z += first(q[i],w[i],e[i]);
					}
					if (first(q[i],w[i],e[i]) == e[i]){
						z += second(q[i],w[i],e[i]);
						if(second(q[i],w[i],e[i]) == q[i]){
							j ++;
						}
						if(second(q[i],w[i],e[i]) == w[i]){
							k ++;
						}
					}
				}
			}
			if(l < n / 2 and k < n / 2){
				if(j >= n / 2){
					
					if(first(q[i],w[i],e[i]) == e[i]){
						l ++;z += first(q[i],w[i],e[i]);
					}
					if (first(q[i],w[i],e[i]) == w[i]){
						k ++;z += first(q[i],w[i],e[i]);
					}
					if (first(q[i],w[i],e[i]) == q[i]){
						z += second(q[i],w[i],e[i]);
						if(second(q[i],w[i],e[i]) == e[i]){
							l ++;
						}
						if(second(q[i],w[i],e[i]) == w[i]){
							k ++;
						}
					}
				}
			}
			if(l < n / 2 and j < n / 2){
				if(k >= n / 2){
					
					if(first(q[i],w[i],e[i]) == q[i]){
						j ++;z += first(q[i],w[i],e[i]);
					}
					if (first(q[i],w[i],e[i]) == e[i]){
						l ++;z += first(q[i],w[i],e[i]);
					}
					if (first(q[i],w[i],e[i]) == w[i]){
						z += second(q[i],w[i],e[i]);
						if(second(q[i],w[i],e[i]) == q[i]){
							j ++;
						}
						if(second(q[i],w[i],e[i]) == e[i]){
							l ++;
						}
					}
				}
			}
			
		}
		cout << z;
	}
	return 0;
}
