#include <bits/stdc++.h>
using namespace std;
int n,m,sc=0,xb=0,zx=0,zy=0;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout << a[i] << " ";
//	}
	for(int i=1;i<=n*m;i++){
		if(sc==a[i]){
			xb=i;
		}
	}
	//cout << xb << endl;
	for(int i=1;i<=m;i++){
		if(xb/n<i||(xb/n==i&&xb%n==0)){
			zy=i;
			//cout <<zy << " ";
			break;
		}
	}
	int tmp=n;
	if(zy%2==1){
		if(xb==n){
			zx=tmp;
		}else{
			zx=xb%n;
		}
	}if(zy%2==0){
		if(xb==n){
			zx=1;
		}else{
			zx=n-xb%n+1;
		}
	}
	cout << zy << " " << zx << endl;
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92

*/
