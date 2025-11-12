#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],c,r,b,d;
bool f(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+m*n+1,f);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			d=i;
			break;
		}
	}
	if(d%n)	c=d/n+1;
	else	c=d/n;
	d%=n*2;
	if(c%2)	r=d;
	else	r=m-d+1;
	cout<<c<<' '<<r;
	return 0;
}