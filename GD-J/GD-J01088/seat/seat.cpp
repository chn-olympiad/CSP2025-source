#include <bits/stdc++.h>
using namespace std;

int n,m,Rs;
int a[10000];

int b[100][100];

int cmp(int a,int b){
	return a > b;	
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	Rs = a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt = 1;
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= n;j++){
			if (i % 2 == 0){
				b[i][n-j+1] = a[cnt++];
			} else {
				b[i][j] = a[cnt++];
			}
		}
	}
	
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= n;j++){
			if (b[i][j] == Rs){
				cout << i << ' ' << j << endl;
			}
		}
	}
	
	return 0;
}
