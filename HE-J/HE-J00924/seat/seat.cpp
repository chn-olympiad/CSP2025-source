#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i;
	cin>>i;
	int a=n*m-i+1;
	int c,r;
	if((a/n)%2==0&&a%n!=0){
		r=a/n+1;
		c=a%n;
	}else if((a/n)%2==0&&a%n==0){
		r=a/n;
		c=n;
	}else if((a/n)%2==1&&a%n!=0){
		r=a/n+1;
		c=n-a%n+1;
	}else if((a/n)%2==1&&a%n==0){
		r=a/n;
		c=1;
	}cout<<c<<r;
	return 0;
}
