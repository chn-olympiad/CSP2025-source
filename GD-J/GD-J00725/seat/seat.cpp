#include <bits/stdc++.h>
using namespace std;
int n,m,b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i<=n*m;i++){
		cin >> b[i];
	}
	
	int r = b[1];
	sort(b+1,b+(n*m)+1);

	int i,j,x;
	
	for(int h = n*m; h>=1; h--){
		if(b[h] == r){
			x = h;
			break;
		}
	}
	if((n*m - x + 1) % n == 0){
		j = (n*m - x + 1) / n;
	}
	else{
		j = (n*m - x + 1) / n + 1;
	}
	
	if(j % 2 == 0 && n % 2 != 0){
		i = n - ((n*m - x + 1)%n)+1;
	}
	else{
		i = (n*m - x + 1) % n;
	}
	
	if(i == 0){
		i = n; 
	}
	
	cout << j << " " << i;
	
	return 0;
} 
