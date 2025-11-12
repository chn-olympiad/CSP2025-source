#include<bits/stdc++.h>
using namespace std;
int s[105];
int n, m;
int R;//小R的编号 

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;

	for(int i = 1; i <= n*m; i++){
		cin >> s[i];
	}
	int r_ = s[1];//小r的成绩 
	
	sort(s + 1, s + n * m + 1, cmp);
	for(int i = 1; i <= n*m; i++){
		if(s[i] == r_){
			R = i;
			break;
		}
	}
	int c = 0;
	int r = 0;
	if(R % m == 0){
		c = R / m;
	} else {
		c = R / m + 1;
	}
	if(c % 2 == 1){
		if(R % m == 0){
			r = m;
		} else {
			r = R % m;
		}
	} else {
		if(R % m == 0){
			r = 1;
		} else {
			r = m - (R % m) + 1; 
		}
	}
	cout << c << " " << r;
	return 0;
}

