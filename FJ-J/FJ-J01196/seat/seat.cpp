#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,asd=0;
int a[205];
int id,fen;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	fen=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		asd++;
		if(a[i]==fen){
			id=asd;
			break;
		}
		
	}
	cout<<id<<endl;
	if(id%n==0){
		c=id/n;
	}
	else{
		c=id/n+1;
	}
	if(c%2==1){
		r=id-(c-1)*n;
	}
	else{
		r=c*n-id+1;
	}
	cout<<c<<' '<<r; 
	return 0;
}
