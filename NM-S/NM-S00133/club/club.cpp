#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = 0;
	cin >> t;
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum4 = 0;
	int sum5 = 0;
	int sum6 = 0;
	int sum7 = 0;
	int sum8 = 0;
	int mum = 0;
	int q = 0;
	int w = 0;
	int e = 0;
	for (int i = 1; i <= t; i++){
		int n = 0;
		cin >> n;
		int num = 0;
		for (int j = 0; j < n; j++){
			int a;
			cin >> a;
			int b; 
			cin >> b; 
			int c;
			cin >> c;
			num = max(a, b);
			num = max(num, c);
			if (mum == 0){
			    if (num == a){
				    sum1 += num;
				    q++;
			    }
			    if (num == b){
			        sum1 += num;
			        w++;
			    }
			    if (num == c){
				    sum1 += num;
				    e++;
			    }	
			}
			if (mum == 1){
			    if (num == a){
				    sum2 += num;
			    }
			    if (num == b){
			        sum2 += num;
			    }
			    if (num == c){
				    sum2 += num;
			    }	
			}
			if (mum == 2){
			    if (num == a){
				    sum3 += num;
			    }
			    if (num == b){
			        sum3 += num;
			    }
			    if (num == c){
				    sum3 += num;
			    }	
			}
			if (mum == 3){
			    if (num == a){
				    sum4 += num;
			    }
			    if (num == b){
			        sum4 += num;
			    }
			    if (num == c){
				    sum4 += num;
			    }	
			}
			if (mum == 4){
			    if (num == a){
				    sum5 += num;
			    }
			    if (num == b){
			        sum5 += num;
			    }
			    if (num == c){
				    sum5 += num;
			    }	
			}
			if (mum == 5){
			    if (num == a){
				    sum6 += num;
			    }
			    if (num == b){
			        sum6 += num;
			    }
			    if (num == c){
				    sum6 += num;
			    }	
			}
				if (mum == 6){
			    if (num == a){
				    sum7 += num;
			    }
			    if (num == b){
			        sum7 += num;
			    }
			    if (num == c){
				    sum7 += num;
			    }	
			}
				if (mum == 7){
			    if (num == a){
				    sum8 += num;
			    }
			    if (num == b){
			        sum8 += num;
			    }
			    if (num == c){
				    sum8 += num;
			    }	
			}
			
	       }
		mum++;
	}
	if (sum1 != 0){
		cout << sum1 << endl;
	}
	if (sum2 != 0){
		cout << sum2 << endl;
	}
	if (sum3 != 0){
	    cout << sum3 << endl;
	}
	if (sum4 != 0){
		cout << sum4 << endl;
	}
	if (sum5 != 0){
		cout << sum5 << endl;
	}
	if (sum6 != 0){
		cout << sum6 << endl;
	}
	if (sum7 != 0){
		cout << sum7 << endl;
	}
	return 0;
} 
