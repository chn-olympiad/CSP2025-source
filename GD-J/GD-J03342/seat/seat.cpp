#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
double r,arr[110],brr[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> arr[i];
	}
	r = arr[1];
	k = n*m;
	sort(arr+1,arr+n*m+1);
	for(int i=1; i<=m; i++){
		if(i%2==1){
			for(int j=1; j<=n; j++){
				brr[j][i] = arr[k--];
			}		
		}
		else{
			for(int j=n; j>=1; j--){
				brr[j][i] = arr[k--];
			}
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(brr[j][i] == r){
				cout << i << ' ' << j;
				return 0;
			}
		}		
	}
} 
