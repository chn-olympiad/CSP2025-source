#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[110],c,r,g=1;
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			g++;
		}
	}
	if(g%n==0 && g>=n){
		c=g/n;
		if(c%2==0){
			r=1;
		}
		else{
			r=n;
		}
	}
	else{
		c=(g/n)+1;
		if(c%2==0){
			r=n-(g%n)+1;
		}
		else{
			r=g%n;
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
