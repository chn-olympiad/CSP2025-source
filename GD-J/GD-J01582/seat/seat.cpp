#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[15][15],b[105];
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> b[1];
	long long cj = b[1];
	for(int i = 2; i <= n * m; i++){
		cin >> b[i];
	}
	sort(b + 1,b + n * m + 1,cmp);
	long long i = 1,j = 1;
	for(int l = 1; l <= n * m; l++){
		a[i][j] = b[l];
		if(j % 2 == 1){
			if(i == n){
				j++;
			}else{
				i++;
			}
		}else{
			if(i == 1){
				j++;
			}else{
				i--;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == cj){
				cout << j << " " << i;
			}
		}
	}
	return 0;
}
