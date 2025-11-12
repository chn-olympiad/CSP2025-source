#include <bits/stdc++.h>
using namespace std;

int n, m, r;
struct s{
	int idd, fenshu;
}a[105];

bool cmp(s xx, s yy){
	return xx.fenshu > yy.fenshu;
}

int main(){
	freopen("seat.in",  "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i].fenshu;
		a[i].idd = i;
	}
	sort(a+1, a+1+n*m, cmp);
	int weizhi;
	for (int i = 1; i <= n*m; i++){
		if (a[i].idd == 1){
			weizhi = i;
			break;
		}
	}
	if (weizhi%n == 0){
		if (weizhi/n%2 == 0)	cout << weizhi/n << ' ' << 1;
		else	cout << weizhi/n << ' ' << n;
		return 0;
	}
	if (weizhi/n%2 == 0){
		cout << weizhi/n+1 << ' ' << weizhi%n;
	}
	else{
		cout << weizhi/n+1 << ' ' << n+1-(weizhi%n);
	}
	return 0;
}
