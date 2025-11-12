#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,a[111],aaa,d;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	aaa=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aaa){
			d=i;
			break;
		}
	}
	c=ceil(d*1.0/n);
	if(c%2==0){
		r=(n+1)-d%n;
	}
	else{
		r=(d-1)%n+1;
	}
	cout<<c<<" "<<r;
	
	
	return 0;
}
