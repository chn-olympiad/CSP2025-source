#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int temp;
bool cmp(int x,int y){
	return x>y;
}
int xb;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	temp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==temp){
			xb=i;
			break;
		}
	}
	if(xb%n==0){
		c=xb/n;
	}
	else{
		c=xb/n+1;
	}
	xb-=(c-1)*n;
	if(c%2==0){
		r=n-xb+1;
	}
	else{
		r=xb;
	}
	cout<<c<<' '<<r;
	return 0;
}
