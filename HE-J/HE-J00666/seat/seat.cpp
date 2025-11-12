#include<bits/stdc++.h>
using namespace std;
int n, m,Q;
int qw=1;
int solve(int z){
	if(z % n == 0){
		return z/n;
	}
	return (z/n)+1;
}
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int N = n*m;
	cin >> Q;
	for(int i = 2 ;i<= N;i++){
		if(i==1){
			cin >> Q;
		}else{
			int x;
			cin >> x;
			if(x > Q){
				qw++;
			}
		}
	}
	int l, h;
	l = solve(qw);
	if(l % 2 != 0){
		h = qw - ((l-1)*n);
	}else{
		h = n - (qw - ((l-1)*n)) + 1;
	}
	cout << l << " " << h;
	return 0;
}
