#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n, m, hang = 1, lie = 1, x = 0;
	cin >> n >> m;
	int s[n * m];
	
	for(int z = 0; z < n * m; z++){
		cin >> s[z];
	}
	for(int i = 0; i < n * m; i++){
		if(s[0] > s[i]){
			x += 1;
		}
		
	}
	if(x >= n - 1){
		hang += 1;
	}
	if(x >= m){
		lie += 0;
	}
	cout << lie << " " << hang;
	return 0;
}
