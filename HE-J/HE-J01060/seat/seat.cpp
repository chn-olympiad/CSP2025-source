#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1010];
long long z[1010];
long long wzm[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int qb = n*m;
	for(int i = 1;i<=qb;i++){
		cin >> z[i];
	}
	int nb = z[1];
	sort(z+1,z+qb+1);
	for(int i = qb;i>=1;i--){
		a[qb-i+1] = z[i];
	}
//	for(int i = 1;i<=qb;i++){
//		cout << a[i] << ' ';
//	}
//	cout << '\n';
	for(int i = 1;i<=m;i++){
		if(i == 1){
			for(int j = 1;j<=n;j++)
				wzm[j][1] = j;
		}
		else if(i%2==0&&i!=1){
			for(int j = 1;j<=n;j++)
				wzm[j][i] = i*n-j+1;
		}
		else if(i%2!=0&&i!=1){
			for(int j = 1;j<=n;j++){
				wzm[j][i] = wzm[1][i-1]+1+j-1;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			wzm[i][j] = a[wzm[i][j]];
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=m;j++){
//			cout << wzm[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(wzm[i][j] == nb){
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
} 
