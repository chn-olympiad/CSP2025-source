#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+2,a+1+n*m);
	int p=n*m;
	for(int i=2;i<=n*m;i++){
		if(a[1]>a[i]){
			p=n*m-i+1;
		}
	}
	int z;
	if(p%n==0){
		z=p/n;
	}
	else{
		z=p/n+1;
	}
	if(z%2==1){
		cout<<z<<" ";
		if(p%n==0) cout<<n;
		else cout<<p%n;
	}
	else{
		cout<<z<<' ';
		if(p%n==0) cout<<1;
		else cout<<n-p%n+1;
	}
	return 0;
}

