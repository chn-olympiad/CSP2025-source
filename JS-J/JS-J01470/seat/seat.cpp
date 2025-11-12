#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,xi;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			xi=n*m-i+1;
			break;
		}
	}
	int xm=xi/n,xn=xi%n;
//	cout<<xi<<" "<<xm<<" ";
	if(xn==0){
		cout<<xm<<n;
	}
	else if((xm+1)%2==1){
		cout<<xm+1<<" "<<xn;
	}else{
		cout<<xm+1<<" "<<n-xn+1;
	}
	return 0;
}
