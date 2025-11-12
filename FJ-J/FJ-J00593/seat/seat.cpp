#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	int n,m;cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}int x = a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int o = 1;o <= n* m;o++){
		if(x == a[o]) x = o;
	}
	int c = (x+n-1) / n ;
	n *= 2;
	x = x % n;
	if(x > n / 2) {
	x = n - x + 1;
	}
	if(x == 0) x = 1;
	cout << c << " " << x;
	return 0;
}