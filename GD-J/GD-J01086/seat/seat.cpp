#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n,m,a[N],sc,p,x,y,k,d[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	sc=a[1];sort(a+1,a+n*m+1);
	for(int i = 1; i <= n*m; i++){
		if(a[i]==sc){
			p=n*m-i+1;break;
		}
	}
	x=1;y=1;
	for(int i = 1; i <= m; i++){
		if(i%2==1){
			for(int j = 1; j <= n; j++){
				d[i][j]=++k;
			}
		}
		if(i%2==0){
			for(int j = n; j >= 1; j--){
				d[i][j]=++k;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(d[i][j]==p){
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
	}
	return 0;
}

