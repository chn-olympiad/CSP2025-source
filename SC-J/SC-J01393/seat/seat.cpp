# include <bits/stdc++.h>
# define int long long
# define endl '\n'
using namespace std;

int a[110];

bool cmp(int cmpa, int cmpb){
	return cmpa > cmpb;
}

signed main(){
//	ios::asnc_with_stdio(false);
//	cout.tie(0);
//	cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, smallR, si=-114;
	cin >> n >> m;
	for(int i=0;i<n*m;i++) cin >> a[i];
	smallR = a[0];
	sort(a, a+n*m, cmp);
	for(int i=0;i<n*m;i++){
		if(a[i] == smallR){
			si = i+1;
			break;
		}
	}
	int x, y;
	x = si / n + (si % n != 0);
	if(x % 2 != 0){
		y = si % n;
		if(y == 0) y = n;
	} else{
		y = n - si % n + 1;
		if(y == n+1) y = 1;
	}
	cout << x << " " << y;
	return 0;
}