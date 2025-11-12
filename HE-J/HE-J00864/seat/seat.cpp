#include <bits/stdc++.h>

using namespace std;

int n,m;

int a[110];

int tmp;

int cnt;

int dir;

bool cmp(int a,int b) {
	return a>b;
} 

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	
	for (int i = 1 ; i <= n*m ; i ++) cin >> a[i];
	
	tmp = a[1];
//	cout << tmp;
	
	sort(a+1,a+1+n*m,cmp);
	
	for (int i = 1 ; i <= n*m ; i ++) {
		if (tmp > a[i]){
			cnt = i-1;
			break;
		}
	}
//	dir = ceil(cnt/n);
	if (cnt%n == 0)
		dir = cnt/n;
	else {
		dir = cnt/n+1;
	}
//	cout << cnt <<" " << n << '\n';
	cout << dir << " ";
	
	if (dir % 2 == 0) {
		cout << n+1-(cnt%n);
	}
	else {
		if (cnt%n == 0){
			cout << cnt;
		}
		else {
			cout << cnt%n;
		}
	}
	return 0;
} 

//2 2
//98 99 100 97

//2 2
//99 100 97 98

//3 3
//94 95 96 97 98 99 100 93 92
