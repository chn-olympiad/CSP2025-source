#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n;
	int m;
	cin >> n >> m;
	int b[n*m+5];
	for(int i = 0;i < n*m;i++){
		cin >> b[i];	
	}
	int c = b[0];
	for(int i = 0;i < n*m;i++){
		for(int j = 0;j < n*m;j++){
			if(b[j] < b[j+1]){
				int v = b[j];
				b[j] = b[j+1];
				b[j+1] = v;
			}
		}
	}
	int y;
	for(int i = 0;i < n*m;i++){
		if(b[i] == c){
			y = i;
			continue;
		}
	}
	int z = (y+1)%n;
	if(z == 0){
		int j = (y+1)/n;
		if(j % 2 == 0){
			cout << j << " " << 1;
		}	
		else{
			cout << j << " " << n;
		}
	}
	else{
		int j = (y+1)/n+1;
		int w = (y+1)-(j-1)*n;
		if(j % 2 == 0){
			cout << j  << " " << (n-w+1);
		}
		else{
			cout << j << " " << w;
		}
	}
	return 0;
}