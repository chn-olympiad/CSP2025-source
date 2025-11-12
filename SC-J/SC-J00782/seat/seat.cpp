#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,tot=0,b,c,r;
	cin>>n>>m;
	b=n*m;
	int a[10005];
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	for(int j=1;j<=b;j++){
		if(a[j]>=a[1]){
			tot++;
		}
	}
	c=tot/n+1;
	if(tot%n==0){
		c=c-1;
	}
	if(c%2==1){
		r=tot%n;
	if(r==0){
		r=n;
	}
	}else{
		r=n-tot%n+1;
	if(tot%n==0){
		r=1;
	}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}