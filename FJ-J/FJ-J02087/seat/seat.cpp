#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],a_r,r_grand,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a_r;
	a[1]=a_r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+(n*m)+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==a_r){
			r_grand=n*m-i+1;
		}
	}
	if(r_grand%n==0){
		c=r_grand/n;
	}
	else{
		c=r_grand/n+1;
	}
	if(c%2==1){
		if(r_grand%n==0){
			r=n;
		}
		else{
			r=r_grand%n;
		}
	}
	else{
		if(r_grand%n==0){
			r=1;
		}
		else{
			r=n-r_grand%n+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

