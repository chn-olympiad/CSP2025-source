#include <bits/stdc++.h>
using namespace std;
int n[10],m[10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101];
	cin >> n >> m;
	for(int i = 0;i<n*m;i++){
		cin >> i;
		a[i] += i;
		int b = a[0];
		a[i] = sort(a[i]);
	}
	for(int j = 0;j<=a;j++){
		if(j==b){
			cout << a[j];
		}
	}
	return 0;
}
