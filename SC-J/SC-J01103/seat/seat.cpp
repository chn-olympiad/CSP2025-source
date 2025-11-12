#include<bits/stdc++.h>
using namespace std;
int ch(int a,int b){
	if(a%b==0)
		return a/b;
	return a/b+1;
}
int n,m,P,a,sum=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>P;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>P)
			sum++;
	}
	c=ch(sum,n);
	if(sum%(2*n)<=n&&sum%(2*n)>0)
		r=sum%(2*n);
	else
		r=n-(sum-n)%n+1;
	cout<<c<<" "<<r;
	return 0;
}