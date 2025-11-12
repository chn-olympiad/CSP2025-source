#include<bits/stdc++.h>
using namespace std;
int a[100];

int main() {
	freopen("seat.in.txt","r",stdin);
	freopen("seat.out.txt","w",stdout);
	int n,m,xm,x,y;
	cin>>n>>m;
	for(int i=0; i<n*m; i++) {
		cin>>a[i];
		if(i==0) {
			xm=a[i];
		}
	}
	int cnt=1;
	for(int i=1; i<n*m; i++) {
		if(a[i]>xm) {
			cnt++;
		}
	}
	int a=cnt/n;

	if(a*n==cnt) {
		if(a%2==0) {
			cout<<a<<" "<<1;

		} else {
			cout<<a<<" "<<n;
		}
	} else {
		cout<<a+1<<' ';
		if(a%2==0) {
			cout<<n-(n*(a+1)-cnt);
		} else {
			cout<<1+(n*(a+1)-cnt);
		}
	}
	cout<<'\n';
	return 0;
}
