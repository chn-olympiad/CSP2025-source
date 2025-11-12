#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[101],b,n,m,c[n][m];
	cin >> n >> m;
	for(int i = 1;i<= n*m;i++){
		cin >> a[i];
		if(i == 1){
			b = a[i];
		}
	}
	sort(a+1,a+1+n*m);
	int cnt = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			c[i][j] = a[cnt];
			cnt++;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout << c[i][j];
			}
		}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if (c[i][j] == b){
				m=i,n=b;
			}
		}
	}
	cout << n << m;
	return 0;
}