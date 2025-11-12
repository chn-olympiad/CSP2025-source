#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n;
	int m;
	int a[15][15];
	int fs[105] = {};
	int b[105] = {0};
	int num = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			a[i][j] = 1;
		}
	}
	for(int i = 1;i <= n*m;i++){
		cin >> fs[i];
		b[fs[i]]++;
	}
	int r = fs[1];
	for(int i = 100;i >= r;i--){
		if(b[i] != 0) num += b[i];
		cout << b[i];
	}
	int paimin = num;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			if((i-1)*n+j == paimin){
				cout << j << ' ' << i;
				break;
			}
		}
	}

return 0;
}