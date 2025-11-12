#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[105],h,l,b[15][15],o=0;
int u=1;
bool f(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1; i<=k; i++) {
		cin>>a[i];
	}
	h=a[1];
	sort(a+1,a+k+1,f);
	for(int i=1; i<=k; i++) {
		if(a[i]==h) {
			l=i;
		}
	}
	int u=1;
	for(int i=1; i<=m; i++) {
		if(i%2==1) {
			for(int j=1; j<=n; j++) {
				b[j][i]=u;
				u++;
			}
		} else {
			for(int j=n;j>=1;j--){
				b[j][i]=u;
				u++;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==l){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}



/*
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

1 8 9  16 17
2 7 10 15 18
3 6 11 14 19
4 5 12 13 20

2 4
3 4 5 6 7 8 9 10
4 1

*/



