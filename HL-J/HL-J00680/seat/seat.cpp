#include<bits/stdc++.h>
using namespace std;
int n,m,nm,a1,c,r,mc=1;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	cin>>a1;
	a[0]=a1;
	for(int i=1;i<nm;i++){
		cin>>a[i];
	}
	for(int i=1;i<nm;i++){
		for(int j=nm+1;j>i;j--){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	while(a1<a[mc]){
		mc+=1;
	}
	if(mc<=n){
		cout<<1<<" "<<mc;
		return 0;
	}
	else if(mc%n==0){
		c=mc/n;
		if(c%2==0){
			r=1;
		}
		else r=n;
	}
	else{
		c=mc/n+1;
		if(c%2==0){
			r=n-mc%n+1;
		}
		else{
			r=mc%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
