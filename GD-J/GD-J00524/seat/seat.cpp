#include<bits/stdc++.h> 
using namespace std;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n*m ;i++){
		cin >> a[i];
	}
	int k = a[1];
	int w;
	sort(a+1,a+n*m+1);
	for(int i = n*m;i >= 1 ;i--){
		if(k == a[i]){
			w =  m*n-i+1;
		}
	}
	int c = w/n;
	int r = w%n;
	if (c == 0){
		c = 1;
	}
	if(r == 0){
		r = n;
	}
	cout << c << ' ' << r;
	return 0;
}
