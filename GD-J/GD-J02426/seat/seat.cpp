#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],z,x,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	z=a[1];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		if(a[i]==z) w=i;
	}
	if((w/n)%2==0) cout<<w/n+1<<" "<<w%n;
	else cout<<w/n+1<<" "<<n-w%n;
	return 0;
}
