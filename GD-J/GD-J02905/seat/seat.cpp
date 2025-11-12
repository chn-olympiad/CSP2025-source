#include<bits/stdc++.h>
using namespace std;

int n,m,a[110],k,h,l,z=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>k) z++;
	}
	l=(z-1)/n+1;
	if(l%2==1) h=(z-1)%n+1;
	else if(l%2==0) h=m-(z-1)%n;
	cout<<l<<" "<<h;
	return 0;
}
