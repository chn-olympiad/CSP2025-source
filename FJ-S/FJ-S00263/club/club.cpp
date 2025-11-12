#include<bits/stdc++.h>
using namespace std;
inline int abczuidazhi(int a , int b , int c){
	if(a > b && b > c){
		return a;
	} else if(a > b && b < c && a > c){
		return a;
	} else if(b > a && a > c){
		return b;
	} else if(b > a && a < c && b > c){
		return b;
	} else if(c > b && b > a){
		return c;
	} else if(c > b && b < a && c > a){
		return c;
	} else if(a == b && b < c){
		return c;
	} else if(a == b && b > c){
		return b;
	} else if(a == c && a > b){
		return a;
	} else if(a == c && a < b){
		return b;
	} else if(b == c && b > a){
		return b; 
	} else if(b == c && b < a){
		return a;
	} else if(a == b && b == c){
		return a;
	}
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	int n; // 新成员个数 
	int a , b , c; // 第i个成员对1 ， 2 ， 3部门满意度 
	cin >> t; // t组数据；
	for(int i = 0;i < t;i++){
		cin >> n;
		int u = 0;//满意值 
		for(int j = 0;j < n;j++){ // 作用：输入满意值 ， 判断学员加入的部门 
			int k = 0 , m = 0 , y = 0;// 第一个部门人数 。 第二个人数 。 第三个人数。
			cin >> a >> b >> c;
			if(n == 2){
				int wa = abczuidazhi(a , b , c);
				if(wa == a){
					k++;
					u += a;
				} else if(wa == b){
					m++;
					u += b;
				} else if(wa == c){
					y++;
					u += c;
				}
				continue;
			}
			int result = abczuidazhi(a , b , c);//abc中最大值 
			if(result == a){
				 k++;
			} else if(result == b){
				m++;
			} else if(result == c){
				y++;
			}
			if(k <= n / 2 || m <= n / 2 || y <= n / 2){
				u += result;
			}
			if(k > n / 2){
			k--;
			if(n / 2 - m >= 1 || n / 2 - y >= 1){
			if(n / 2 - m >= 1 && n / 2 - y >= 1){
			if(b > c){
				m++;
				u += b;
			} else {
				y++;
				u += c;
			}
		} else if(n / 2 - m >= 1 && n / 2 - y < 1){
			m++;
			u += b;
		} else if(n / 2 - m < 1 && n / 2 - y >= 1){
			y++;
			u += c;
		}
	}
} else if(m > n / 2){
	m--;
	if(n / 2 - k >= 1 || n / 2 - y >= 1){
		if(n / 2 - k >= 1 && n / 2 - y >= 1){
			if(a > c){
				k++;
				u += a;
			} else {
				y++;
				u += c;
			}
		} else if(n / 2 - k >= 1 && n / 2 - y < 1){
			k++;
			u += a;
		} else if(n / 2 - k < 1 && n / 2 - y >= 1){
			y++;
			u += c;
		}
	}
} else if(y > n / 2){
	y--;
	if(n / 2 - k >= 1 || n / 2 - m >= 1){
		if(n / 2 - k >= 1 && n / 2 - m >= 1){
			if(a > b){
				k++;
				u += a;
			} else {
				y++;
				u += b;
			}
		} else if(n / 2 - k >= 1 && n / 2 - m < 1){
			k++;
			u += a;
		} else if(n / 2 - k < 1 && n / 2 - m >= 1){
			y++;
			u += b;
			}
		}
	}
}
		cout << u;
	}
}
