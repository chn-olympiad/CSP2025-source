#include<bits/stdc++.h>
using namespace std;
const int N = 225;

int a[N];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m; //n行m列 
	int peo = n * m;
	int ans;
	cin >> ans;
	a[1] = ans;
	for(int i = 2;i <= peo;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + peo, cmp);
	int rnk = 0; //rank 
	for(int i = 1;i <= peo;i++){
		if(a[i] == ans){
			rnk = i;
		}
	}
	int c, r;//c列r行 
	c = ceil(rnk * 1.0 / n);
	if(c % 2 == 0){ //如果是偶数列，从下往上数 
		if(rnk % n){ //不是n的倍数 
			r = n - rnk % n + 1;
		}
		else r = 1;
	} 
	else{ //奇数列，从上往下数 
		if(rnk % n){ //如果不是n的倍数 
			r = rnk % n;
		}
		else r = n;
	}
	cout << c << ' ' << r;
	
	return 0;
}