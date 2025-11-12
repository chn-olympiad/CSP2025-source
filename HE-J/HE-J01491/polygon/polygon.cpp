#include<bits/stdc++.h>
using namespace std;
int a[10100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int m=0;
	int h=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		m=max(a[i],m);
		h+=a[i];
	}
	if(h>2*m && n==3) cout<<1;
	else cout<<0;	
	
	return 0;
}
