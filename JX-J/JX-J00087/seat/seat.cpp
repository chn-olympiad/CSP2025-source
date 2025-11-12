#include<iostream>
using namespace std;
int main(){
	int a[105];
	int n,m,b,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	for(int i=1;i<=a.size;i++){
		for(int j=1;j<=a.size-1;j++){
			if(a[i]<=a[i+1]){
				c=a[i];
				a[i]=a[i+1];
				a[i+1]=c;}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(b==a[i]){
			b=i;}
	}
	if(i%n!=0){
		c=i/n+1;}
	else(){
		c=i/n;}
	if(c%2==0){
		r=c*m+1-b;}
	else(){
		r=b-(c-1)*m}
	cout<<c<<r;
	return 0;
}
