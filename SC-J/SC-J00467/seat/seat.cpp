#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
int a[105];
int cmp(int x, int y){
	return x > y;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int t = 0;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int x = 0, y = 0, cnt = 0, pte = 1;
	while(a[pte] >= t){
		cnt++;
		pte++;
	}
	if(cnt % n != 0){
		y = cnt / n + 1;
	}else{
		y = cnt / n;
	}
	x = cnt % n;
	if(y % 2 == 0){
		if(x == 0){
			x = 1;
		}
		cout << y << " " << n - x + 1;
	}else{
		if(x == 0){
			x = n;
		}
		cout << y << " " << x;
	}
	return 0;
}