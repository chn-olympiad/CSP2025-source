#include<bits/stdc++.h>
using namespace std;
int a[400];
int n,m,zw;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
	if(a[i]>a[1])zw++;
}
zw++;
int c,r;
if(zw==1)cout<<1<<" "<<1;
else{
	c=zw/n;
	if(zw%n)c++;
	r=abs(zw-c*n);
	if(r==0){
		if(c%2)r=n;
		else r=1;
	}
	else if(c%2==0)r=n-r+1;
	else r=n-r;
	cout<<c<<" "<<r;
}

return 0;
}
