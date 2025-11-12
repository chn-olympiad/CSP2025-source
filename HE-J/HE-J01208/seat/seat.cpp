#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m,R=1;
	for(int i=1;i<=l;i++) {
		cin>>a[i];
		if(a[i]>a[1]) R++;
}
	int c=R/n+1;
	if(c%2==1) cout<<c<<" "<<R-m*(c-1);
	else cout<<c<<" "<<m*c-R+1;
	return 0;
}

