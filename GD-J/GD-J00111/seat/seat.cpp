#include <bits/stdc++.h>
using namespace std;
int n,m,x,ind=1,c,r,f=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> x;
	for (int i = 2;i <= n*m;i++){
		int a;
		cin >> a;
		if (a > x) ind++;
	} 
	
	if (ind % n == 0){
		c = ind / n;
		f = 1;
	}
	else c = ind / n + 1;
	
	if (f){
		if (c % 2 == 0) r = 1;
		else r = n;
	}
	else{
		if (c % 2 == 0) r = n - (ind % n) + 1;
		else r = ind % n;
	}
	cout << c << " " << r << endl; 
	return 0;
}
