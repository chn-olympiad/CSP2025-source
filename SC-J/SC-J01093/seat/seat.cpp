#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],x,y,z,w,e;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	for(int i=1;i<=n*m;i++) {
		for(int j=1;j<i;j++) {
			if(a[i]>a[j]) {
				int q=a[i];
				a[i]=a[j];
				a[j]=q;
			}
		}
	}
	for(int i=1;i<=n*m;i++) {
		if(a[i]==x) {
			y=i;
			break;
		}
	}
	z=y/n;
	w=y%n;
	if(w==0){
		if(z%2==0) cout<<z<<" "<<1;
		else cout<<z<<" "<<n;
	}
	else if((z+1)%2==0) cout<<z+1<<" "<<n-w+1;
	else cout<<z+1<<" "<<w;
	return 0;
} 