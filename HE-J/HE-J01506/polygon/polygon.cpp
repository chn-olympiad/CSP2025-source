#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,x,y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3) cout<<0;
	if(n==3) {
		x=a[1]+a[2]+a[3];
		y=max(a[1],max(a[2],a[3]));
		if(x>2*y) cout<<1;
	}
	return 0;
}
