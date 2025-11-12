#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int a[N];
int b[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int zhi = 0;
	cin >> n >> m;
	int num = n * m;
	for(int i = 1;i <= num;i++){
		cin >> a[i];
	}
	int r = a[1];
	int dawei = 0;
	int nu = num;
	for(int j = 1;j <= num;j++){
		int da = 0;
		for(int i = 1;i <= nu;i++){
			if(a[i] > da){
				da = a[i];
				dawei = i;
			}
		}
		for(int m = dawei;m <= nu;m++){
			a[m] = a[m + 1];
		}
		
		zhi++;
		b[zhi] = da;
		nu--; 
	}
	int rwei = 1;
	for(int i = 1;i <= num;i++){
		if(b[i] != r){
			rwei++;
		}
		if(b[i] == r){
			break;
		}
	}
	int hang = n,lie = m;
	int h1,l1;
	int ce = rwei % hang;
	if(ce != 0){
		l1 = rwei / hang + 1;
	}else if(ce == 0){
		l1 = rwei / hang;
	}
	int shi = l1 % 2;
	int dan = 0;
	if(shi == 0){
		dan = 0;
	}else{
		dan = 1;
	}
	if(ce != 0){
		if(dan == 1){
			h1 = ce;
		}else if(dan == 0){
			h1 = n - ce + 1;
		}
	}else if(ce == 0){
		if(dan = 1){
			h1 = n;
		}
		else if(dan == 1){
			h1 = 1;
		}
	}
	cout << l1 << " " << h1;

	return 0;
}