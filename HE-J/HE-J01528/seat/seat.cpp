#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	bool si = false;
	int n,m,k[121],middle,pm = 1,c = 0,r = 0;
	cin >> n >> m;
	for (int i = 0;i < n * m;i++){
		cin >> k[i];
	}
	r = k[0];
	for (int j = 0;j < sqrt(n * m);j++){
		for (int i = 0;i < (n * m - 1);i++){
			if (k[i] < k[i + 1]){
				middle = k[i];
				k[i] = k[i + 1];
				k[i+1] = middle;
				si = true;
			}
		}
		if (si == false){
			break;
		}
		si = false;
	}
	for(int i = 0;i < n*m;i++){
		if (k[i] == r){
			pm = i + 1;
			break;
		}
	}
	int x = pm / n;
	int y = pm % n;
	if (x * n != pm){
		x += 1;
	}
	if (pm / n < 1){
		c = 1;
		r = pm;
	}
	else{
		c = x;
		if (y == 0){
			if (c % 2 != 0){
				r = n;
			}
			else{
				r = 1;
			}
		}
		else{
			if (c % 2 != 0){
				r = y;
			}
			else{
				r = n + 1 - y;
			}
		}
	}
	cout << c <<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
