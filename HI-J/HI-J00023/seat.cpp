#include<bits/stdc++.h>
using namespace std;
int R,n,m,hang,c,r,rmn;
int a[105];
bool comp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		R=a[1];
	}
	sort(a+1,a+1+n*m,comp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			R=i;
		}
	}
	rmn=R%n;
	if(R%n==0){
		c=R/n;
	}
	if(R%n!=0){
		c=R/n+1;
	}
	if(c%2==0){//Å¼Êý 
		r=n-rmn+1;
	}
	if(c%2!=0&&R>n){//µ¥Êý 
		r=rmn;
	}
	if(c==1) r=R; 
	cout<<c<<" "<<r;
	return 0;
} 
