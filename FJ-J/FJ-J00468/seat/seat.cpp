#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,x1=0,c,x,y;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	x1=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m*n;i++){
		if(a[n*m-i+1]==x1){
			c=i;
			break;
		}
	}
	if(c%n==0){
		x=c/n;
		if(x%2==0){
			y=1;
		}
		else{
			y=n;
		}
	}
	else{
		x=c/n+1;
		if(x%2==0)y=n-c%n+1;
		else y=c%n;
	}
	cout<<x<<" "<<y;
	return 0;
}
