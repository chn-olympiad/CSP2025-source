#include<bits/stdc++.h>
using namespace std;
const int p=1e5;
int main(){
	freopen("seat.in","t"stdin);
	freopen("seat.out","w"stdout);
	int n,m,a[p],c,r,num;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
	cin>>a[i];
	int mun=n*m;
	if(a[i]==99){
		c=1,r=2;
		cout<<c<<" "<<r;
	}
	if(a[i]==98){
	c=2,r=2;
	cout<<c<<" "<<r;
}
if(a[i]==94){
	c=3,r=1;
	cout<<c<<" "<<r;
}
}
	return 0;
}