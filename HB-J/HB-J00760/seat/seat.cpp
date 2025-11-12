#include<bits/stdc++.h>
using namespace std;
const int MM=110;
int a[MM],m,R,n,tmp;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R) tmp=i;
	}
	tmp=n*m-tmp+1;
	if(tmp%n==0) c=tmp/n;		
	else c=tmp/n+1;
	if(c%2==0){
		if(tmp%n==0) r=1;
		if(tmp==(c-1)*n+1) r=n;
		else r=n-(tmp%n)+1;
	}
	else {
		if(tmp%n==0) r=n;
		else r=tmp%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
