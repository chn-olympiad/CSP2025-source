#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],a1,id,c,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==a1){
			id=n*m-i+1;
			break;
		}
	}
	c=id/n;
	if(id%n!=0){
		++c;
	}
	if(c%2==0){
		r=n-id%n+1;
	}else{
		if(id%n!=0) r=id%n;
		else r=n;
	}
	cout<<c<<" "<<r;
	return 0;
}
