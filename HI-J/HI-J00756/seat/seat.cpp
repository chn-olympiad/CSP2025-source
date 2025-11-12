#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a > b){
		return true; 
	}else if(a < b){
		return false;
	}
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[10][10];
	int n , m;
	cin >> n >> m;
	int per_1[n*m];
	for(int i = 0;i < n*m;i++){
		cin >> per_1[i];
	}
	sort(per_1 , per_1 + n*m , cmp);
	int per[n*m];
	for(int i = 0;i < n*m;i++){
		per[i] = per_1[i];
	}
	for(int p = 0;p < n*m;p++){
		for(int j = 1,i = 1;j <= m,i <= n;j++,i++){
			a[i][j] = per[p];
			if(per_1[0] == per[p]){
				//ур╣╫ак
				cout << i << " " << j;
				return 0; 
			}
			if(j == n+1){
				j++;
			}
		}
	}
	return 0;	
}
