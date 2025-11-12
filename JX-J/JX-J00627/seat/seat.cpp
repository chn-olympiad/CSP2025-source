#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,c,d,e;
	c=n*m;
	int a[]={}
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a[1]=b;
	for(int j=1;j<=a[c],j++){
		if(a[i]<a[j]){
			a[i+1];
		}
	}
	d=b/n;
	e=b%n;
	if(b%n!=0&&b/n==0){
		d=d+1
	}
	if(e==0){
		e=b;
	}
	cout<<d<<" "<<e;
}
