#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],x,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(x==a[i]){
			x=n*m-i+1;
			break;
		}
	}
	c=x/n;
	if(x%n!=0){
		c++;
	}
	r=x%n;
	if(c%2==0){
		r=n-r+1;
	}
	if(r==0){
		r=n;
	}
	if(r==n+1){
		r=1;
	}
	cout << c << ' ' << r;
	return 0;
}
