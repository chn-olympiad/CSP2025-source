#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a) ans++;
	}
	c=(ans-1)/n+1;
	if(c%2==1){
		d=(ans-1)%n+1;
	}else{
		d=n-(ans-1)%n;
	}
	cout<<c<<" "<<d;
	return 0;
}
