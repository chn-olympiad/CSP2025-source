#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long int n,m,a[n*m],y,x=0;
	cin>>n>>m;
	cin>>a[1];
	y=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i+1]>y){
			x++;
		}
	}
	if(x<n){
		cout<<1<<" "<<1+x;
	}else if(x==n){
		cout<<2<<" "<<n;
	}else if(x>n && x<n+m){
		cout<<2<<" "<<n-(x-n);
	}else if(x==m+n){
		cout<<3<<" "<<1;
	}else if(x>n+m && x<n*m){
		if(n-(x-n)<0){
			cout<<m-(x/n)<<" "<<-(n-(x-n));
		}else{
			cout<<m-(x/n)<<" "<<n-(x-n);
		}
	}
	return 0;
}
