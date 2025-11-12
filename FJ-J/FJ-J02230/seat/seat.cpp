#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,sum=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a)sum++;
	}
	c=sum/n+1;r=sum%n;
	if(r==0){
		c--,r=n;
	}
	if(c%2==0)r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
