#include<bits/stdc++.h>
using namespace std;
int n,m;
int bigger = 1;
int a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int nm = (n * m);
	for(int i = 0; i < nm; ++i){
		int x;
		cin >> x;
		if(i == 0){
			a1 = x;
		}
		if(x > a1){
			bigger++;
		}
	}
	int hang;
	if(bigger % n == 0){
		hang = bigger / n;
	} else {
		hang = (bigger / n) + 1;
	}
	int lie;
	if(hang % 2 == 1){
		if(bigger % n == 0){
			lie = n;
		} else {
			lie = bigger % n;
		}
	} else {
		if(bigger % n == 0){
			lie = 1;
		} else {
			lie = n - (bigger % n) + 1;
		}
	}
	cout << hang << " " << lie;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
