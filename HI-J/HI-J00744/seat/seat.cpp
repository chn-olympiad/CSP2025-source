#include <bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
	return a>b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int t1=a[1];
	sort(a+1,a+1+n*m,comp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<' ';
//	}
	for(int i=1; i<=n*m; i++) {
		if(a[i]==t1) {
			int jian=i%n;
//			cout<<jian<<' ';
			int y=i/n;
//			cout<<y<<' ';
			if(jian==0){
				if(y%2==1){
					cout<<y<<' '<<n;
				}else{
					cout<<y<<' '<<1;
				}
			}else{
				if((y+1)%2==1){
					cout<<y+1<<' '<<jian;
				}else{
					cout<<y+1<<' '<<n+1-jian;
				}
			}
		}
	}
	return 0;
}
