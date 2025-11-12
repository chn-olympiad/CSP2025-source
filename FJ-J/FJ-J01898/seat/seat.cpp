#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[225],n,m,c,d=1,e=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	c=a[1];
	sort(a+1,a+n*m+1);
	int i=n*m+1;
	while(i--){
		if(c==a[i])break;
	}
	i=n*m-i+1;
	d=i/n;
	e=i%n;
	if(d%2==0){
		if(e>0)cout<<d+1<<" "<<e;
		if(e==0)cout<<d<<" "<<1;
	}
	if(d%2!=0){
		if(e>0)cout<<d+1<<" "<<n-e+1;
		if(e==0)cout<<d<<" "<<n;
	}
	return 0;
}
