#include <bits/stdc++.h>
using namespace std;
int n,m;
int c[110];
bool cmp(int xx,int yy){
	return xx > yy;
}
int csp[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> c[i];
	}
	int r = c[1];
	//cout << r << ' ';
	int a = 1;
	int b = 1;
	sort(c + 1,c + n * m,cmp);
	//for(int i = 1;i <= n * m;i++){
	//	cout << c[i] << ' ';
	//}
	//cout << endl;
	for(int i = 1;i <= n * m;i++){
		csp[a][b] = c[i];
		if(a % 2 == 0){
			if(b == 1){
				a++;
				continue;
			}
			b--;
		}
		else{
			if(b == n){
				a++;
				continue;
			}
			b++;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(csp[i][j] == r){
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
	}
}
