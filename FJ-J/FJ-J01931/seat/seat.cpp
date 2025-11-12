#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b) {
	return a>=b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x;
	for(int i=1; i<=n*m; i++) {
		if(a[i]==a1) {
			x=i;
			break;
		}
	}
	int x0=x/2/n;
	int y0=x%(2*n);
	if(x0==0&&y0<=n) cout<<1<<" "<<y0;
	else if(x0==0&&y0>n) cout<<2<<" "<<n*2-y0+1;
	else if(y0>n) cout<<x0*2+1<<" "<<n*2-y0+1;
	else cout<<x0*2+1<<" "<<y0;
	return 0;
}
