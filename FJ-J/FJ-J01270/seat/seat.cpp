#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b) {
	if(a<b) {
		return 0;
	}
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,si,x,y;
	cin >> n >> m;
	int s[n*m+1]={};
	cin >> si;
	s[1]=si;
	for(int i=2;i<=n*m;i++) {
		cin >> s[i];
	}
	sort(s+1,s+n*m,cmp);
	for(int j=1;j<=n*m;j++) {
		if(s[j]==si) {
			if(j<=n) {
				y=1;
			}
			else {
				y=j/n+1;
			}
			int yu=j%n;
			if(y%2==0) {
				if(yu==0) {
					x=1;
				}
				else {
					x=n-yu+1;
				}
			}
			else {
				if(yu==0) {
					x=n;
				}
				else {
					x=yu;
				}
			}
		}
	}
	cout << y << " " << x;
	return 0;
} 
