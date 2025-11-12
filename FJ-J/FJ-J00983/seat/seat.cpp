#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n*m; i++)cin>>a[i];
	int mark=a[0];
	sort(a,a+n*m,cmp);
	int lon,hig;
	for(int i=0; i<n*m; i++) {
		if(a[i]==mark) {
			mark=i+1;
			break;
		}
	}
	lon=ceil(1.0*mark/n);
	if(lon%2==1)hig=(mark%n==0?n:mark%n);
	else hig=n-(mark%n==0?n:mark%n)+1;
	cout<<lon<<' '<<hig;
	return 0;
}

