#include<bits/stdc++.h>
using namespace std;
int a[20][20], num[150];

bool cmp(int a1,int a2){
	if(a1 > a2) return true;
	return false;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, x, t = 1;
	cin >> n >> m >> x;
	num[1] = x;
	for(int i = 2; i <= n*m; i++) cin >> num[i];
	sort(num+ 1, num + n*m+ 1, cmp);
	for(int i = 1; i <= m; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++){
		 	a[j][i] = num[t];
			t++;
			}
		}else{
			for(int j = n; j >= 1; j--){
		 	a[j][i] = num[t];
		 	t++;		 	
			}		
		}	
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == x) {
			cout << j << " " << i;
			break;
			}
		} 
	}
	return 0;
}
