#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int tx,xr;
int t,x,r;
int cap(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	tx=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cap);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tx){
			xr=i;
			break;
		}
	}
	if (xr%n==0){
		t=xr/n;
		x=n;
	}
	else{
		t=xr/n+1;
		x=xr%n;
	}
	if(t%2==0){
		cout<<t<<" "<<n-x+1;
	}
	else{
		cout<<t<<" "<<x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}