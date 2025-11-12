#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int xy,z;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xy=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xy) z=i;
	}
	int c=0,r=0;
	if(z%n==0){
		c += z/n;	
	}else if(z%n!=0) {
		c += z/n+1;
	}
	if(c%2==1){
		if(z%n==0) r += n;
		else if(z%n!=0) r += z%n;
	}else if(c%2==0){
		if(z%n==0) r+=1;
		else if(z%n!=0) r += n-z%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
