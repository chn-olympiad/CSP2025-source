#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, R, x, y, t, a[105], s[15][15];
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i]; 
	}
	R = a[1];
	
	for(int i=1; i<n*m; i++){
		for(int j=i; j<n*m; j++){
			if(a[j] < a[j+1]){
				int d=a[j];
				a[j] = a[j+1];
				a[j+1] = d;
			}
		}
		if(a[i] == R){
			if(i%m == 0){
				x = i/m;
				if(x%2==0){
					y = 1;
				}else{
					y = m;
				}
			}else{
				x = i/m+1;
				if(x%2==1){
					y = i%m;
				}else{
					y = m-i%m+1;
				}
			}
			cout<<x<<" "<<y;
			return 0;
		}
		t = i+1;
	}
	if(a[t] == R){
		if(t%m == 0){
			x = t/m;
			if(x%2==0){
				y = 1;
			}else{
				y = m;
			}
		}else{
			x = t/m+1;
			if(x%2==1){
				y = t%m;
			}else{
				y = m-t%m;
			}
		}
	}
	cout<<x<<" "<<y;
	
	return 0;
}
