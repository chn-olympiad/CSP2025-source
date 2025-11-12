#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, pos=1;//先n行 后m列 
	cin >> n >> m;
	int arr[n*m];
	for (int i=0; i<n*m; ++i) cin >> arr[i];
	for (int i=1; i<n*m; ++i){
		if (arr[i]>arr[0]) pos++;
	}
	int c = (pos-1)/n+1, r;
	if (c%2==1) r=(pos-1)%n+1;
	if (c%2==0) r=m-(pos-1)%n;
	cout << c << ' ' << r;
	return 0;
} 
