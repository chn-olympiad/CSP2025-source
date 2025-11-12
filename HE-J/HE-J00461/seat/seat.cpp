#include<bits/stdc++.h>
using namespace std;
int a[110],r,n,m,ansx,ansy;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	int cntt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<n*m;i++){
		if(a[i]==cntt) {
			r=i;
			break;
		}
	}
	ansx=r/n;
	if(r>ansx*n) {
		ansx++;
	}
	if(ansx%2==1) {
		if(r==n) {
			ansy=n;
		}
		else {
			ansy=r%n;
		}
	}
	else {
		ansy=n-r%n+1;
	}
	cout<<ansx<<' '<<ansy;
	return 0;
}
