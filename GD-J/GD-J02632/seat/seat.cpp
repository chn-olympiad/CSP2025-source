#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005] = {};
bool cmp(int a1,int b1){
	return a1 > b1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int js = n*m,f = a[1];
	sort(a+1,a+js+1,cmp);
	//for (int i = 1; i <= js; i++){
	//	cout << a[i] << " ";
	//	
	//}
	for (int i = 1; i <= js; i++){
		if (a[i] == f){
			if (i % n == 0){
				if ((i / n) % 2){
					cout << (i/n) << " " << n;
					return 0;
				}else{
					cout << (i/n) << " " << 1;
					return 0;
				}
			}else{
				if (((i / n) + 1) % 2){
					cout << (i / n)+1 << " " << i % n;
					return 0;
				}else{
					cout << (i / n)+1 << " " << n - (i % n) + 1;
					return 0;
				}
			}
		}
	}
	return 0;
}
