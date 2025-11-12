#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,c,r,e,f;
	int i[101];
	for (int j = 0;j < n*m;j++){
		cin >> i;
	}
	//i = {98,99,100,97}
	f = i[1];
	for (int k = 0;k < n*m;k++){
		for (int l = 1;l < n*m;l++){
			if (i[l] > i[l-1]){
				e = i[l-1];
				i[l-1] = i[l];
				i[l] = e;
			}
		}
	}
	for (int o = 0;o < n*m;o++){
		if (i[o] = f){
			cout << o;
		}
	}
	return 0; 
}
