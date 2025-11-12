#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],jl=0,wz=0,x=1,y=1;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)cin>>a[i];
	jl=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m; i>=1; i--) {
		wz++;
		if(a[i]==jl)break;
	}
	wz--;
	while(1) {
		if(y%2==1) {
			if(wz<=0)break;
			x++,wz--;
			if(x==n) {
			if(wz<=0)break;
				y++,wz--;
			}
		} else if(y%2==0) {
			if(wz<=0)break;
			x--,wz--;
			if(x==1) {
			if(wz<=0)break;
				y++,wz--;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

4 5
1 19 18 17 16 15 14 20 12 11 13 9 8 7 6 5 4 3 2 10
*/
