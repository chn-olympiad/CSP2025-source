#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,R;
	int arr[n][m];
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	R = a[1];
	for(int i=1; i<=n*m; i++){
		for(int j=1; j<=n*m; j++){
			if(a[j] < a[j+1]){
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
		if(a[i] < a[i+1]){
				int n = a[i+1];
				a[i+1] = a[i];
				a[i] = n;
		} else{
			continue;
		}	
	}
	for(int i=1; i<=n*m; i++){
		for(int j=1; j<=i; j++){
			if(i > n){
				arr[i+1][j] = a[i];
			}
			if(j > m){
				arr[i][j+1] = a[j];
			}
			arr[i][j] = a[i];
		}
	}
	for(int i=1; i<=n*m; i++)
		for(int j=1; j<=i; j++)
			cout << arr[n][m];
	return 0;
}

