#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//3 3 94 95 96 97 98 99 100 93 92
	int n,m;
	cin >> n >>m;
	int a1[n*m];
	int b;
	cin >>b;
	a1[0] = b;
	for (int i = 1;i < n*m;i++){
		cin >>a1[i];
	}
	sort(a1,a1+n*m);
	int a[n*m];
	int c = 0;
	for (int i = n*m-1;i >= 0;i--){
		a[c] = a1[i];
		c++;
	}
	int x = 1,y =1;
	bool ok = 1;
	for (int i = 0;i < n*m;i++){
		if (a[i] == b){
			cout << x << " " <<y;
			return 0;
		}
		if ((i+1) % n == 0){
			if (ok){
				ok = 0;
				x+=1;
			}else{
				ok = 1;
				x+=1; 
			}
		}else{
			if (ok){
				y+=1;
			}else{
				y-=1;
			}
		}
	}
}
