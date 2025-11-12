#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int r;
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	r =a[1];
	int q;
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i] == r){
			q = i;
			break ;
		}
	}
	int x = ceil(1.0*q/n);
	int y;
	if(x%2!=0){
		if(q%n==0){
			y = n;
		}else{
			y = q%n;
		}
	}else{
		if(q%n==0){
			y = 1;
		}else{
			y = n-q%n+1;
		}
	}
	cout << x << " " << y << endl;
	return 0; 
}
