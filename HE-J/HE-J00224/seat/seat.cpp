#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,c,r;
bool t(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	k=a[0];
	sort(a,a+n*m,t);
	for(int i=0;i<n*m;i++){
		c=i/n+1;
		if(c%2!=0) r=i%n+1;
		else r=n-i%n;
		if(a[i]==k) cout<<c<<" "<<r;
	}
	return 0;
}
