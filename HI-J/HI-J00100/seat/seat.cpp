#include<bits/stdc++.h>
using namespace std;
long long n, m, c, r, k=1;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int t = n*m;
	int m[n*m];
	for(int i=1; i<=t; i++){
		cin >>m[i];
	}
	int r = m[1];
	sort(m, m+t+1);
	while(m[k++] != r){}
	for(int i=1; i<=t; i++){
		cout << m[i];
	}
	k -= -2;
	k = t-k;
	cout << k << endl;
	c = k/n + (k%n>0);
	if(c%2){
		if(k%n){
			r = k/n;
		}else r = n;
	}else {
		if(k % n){
			r = n-(k%n)+1;
		}r = 1;
	} 
	cout << c <<" " << r;
	return 0;
}
