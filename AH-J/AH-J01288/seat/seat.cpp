#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],xh,boc;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)boc=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(boc==a[i]){
			xh=n*m-i+1;
			break;
		}
	}
	cout<<(xh+n-1)/n;
	if(((xh+n-1)/n)%2==1){
		if(xh%n==0)cout<<" "<<n;
		else cout<<" "<<xh%n;
	}
	else cout<<" "<<n-xh%n;
	return 0;
}
