#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,s,p,cnt = 0;
int a[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a[1];
	s = m * n;
	p = a[1];
	for(int i = 2;i <= s;i++){
		cin >> a[i];
		if(a[i] > a[1]){
			cnt++;
		}
	}
	cnt += 1;
	if(cnt % n == 0){
		if((cnt / n) % 2 == 0){
			c = cnt / n;
			r = 1;
		}
		else{
			c = cnt / n;
			r = n;
		}
	}
	else{
		if((cnt / n) % 2 == 0){
			c = cnt / n + 1;
			r = (cnt % n);
		}
		else{
			c = cnt / n + 1;
			r = n - (cnt % n) + 1;
		}
	}
	cout << c << ' ' << r;
	return 0;
}
