#include<bits/stdc++.h>
using namespace std;

int n, m;   //行 n,列 m
int a, b;   //小R的座位号， 行 a,列 b
int x;      //小R分数
int y;      //小R排名
double t;
int c[1000];

int main(){
	ios::sync_with_stdio(false);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m>>x;
	for(int i = 1; i < n * m; i++){
		cin>>c[i];
	}
	c[0] = x;
	sort(c, c+m*n);
	for(int i = 0; i < n * m; i++){
		if(c[i] == x) y = n*m - i;
	}

	if(y%n == 0) b = y/n;
	else b = y/n + 1;          // y/n向上取整
	if(b % 2 == 0){
		a = n - (y % n) + 1;
	}
	else{
		if(y % n != 0) a = y % n;
		else a = n;
	}
	cout<<b<<' '<<a;
	return 0;
}
