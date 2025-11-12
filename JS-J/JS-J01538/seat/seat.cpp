#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[105];
int b[15][15];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int T = n * m;
	for(int i = 1;i <= T;i++){
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + T + 1,cmp);
	b[1][1] = 1;
	for(int j = 1;j <= m;j++){
		if(j % 2 == 1){
			for(int i = 1;i <= n;i++){
				if(i == 1 && j != 1){
					b[i][j] = b[i][j - 1] + 1;
				}else{
					b[i][j] = b[i - 1][j] + 1;
				}
			}
		}else if(j % 2 == 0){
			for(int i = n;i >= 1;i--){
				if(i == n){
					b[i][j] = b[i][j - 1] + 1;
				}else{
					b[i][j] = b[i + 1][j] + 1;
				}
			}
		}
	}
	for(int i = 1;i <= T;i++){
		if(a[i] == x){
			y = i;
			break;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(b[i][j] == y){
				cout << j << " " << i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
