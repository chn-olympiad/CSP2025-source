#include<bits/stdc++.h>
using namespace std;
int a[123];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a[0]=a[1];
	sort(a+1,a+1+n*m);
	int j=0,x,c,r;
	for(int i=n*m;i>=1;i--){
		j++;
		if(a[i]==a[0]){
			x=j;
		}
	}
	if(x%n==0){
		c=x/n;
		if(c%2==1){
			r=n;
		}
		if(c%2==0){
			r=1;
		}
	}
	if(x%n!=0){
		c=x/n+1;
		if(c%2==1){
			r=x%n;
		}
		if(c%2==0){
			r=n-x%n+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
