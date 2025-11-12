#include <bits/stdc++.h>
using namespace std;
int n,m,a[105][105],k=0,rk=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(i==1&&j==1){
				k=a[i][j];
			}else{
				if(a[i][j]>k) rk++;
			}
		}
	}
	int x=ceil(rk*1.0/n),ls=rk%n,y;
	if(ls==0) ls=n;
	if(x%2==1){
		y=ls;
	}else{
		y=n-ls+1;
	}
	cout << x << " " << y;
	return 0;
}
