#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],rs,rp,rx,ry;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n * m;i++){
		cin >> a[i];
	}
	rs = a[0];
	sort(a,a + n * m);
	for(int i = 0;i < n * m;i++){
		if(a[i] == rs){
			rp = n * m - i;
		}
	}
//	cout << rp << endl;
	if(rp % n == 0){
		rx = rp / n;
	}
	else{
		rx = rp / n + 1;
	}
	if(rx % 2 == 0){
		if(rp % n == 0){
			ry = 1;
		}
		else{
			ry = n - rp % n + 1;
		}
	}
	else{
		if(rp % n == 0){
			ry = n;
		}
		else{
			ry = rp % n;
		}
	}
	cout << rx << " " << ry << endl;
	return 0;
}
