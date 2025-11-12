#include<bits/stdc++.h>
using namespace std;
int n,m,a[17],b[17][17],r,pos,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--) {
		if(a[i]==r) {
			pos=n*m-i+1;
	}
	}
	y=pos/n;
	if(pos%n!=0) y++;
	if(y%2==1){
		if(pos%n!=0) x=pos%n;
		else x=n;
	}
	if(y%2==0){
		if(pos%n!=0) x=n-(pos%n)+1;
		else x=1;
	}
	cout<<y<<" "<<x;
	return 0;
} 
