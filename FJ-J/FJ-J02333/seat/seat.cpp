#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=2;i<=n*m;i++)
		if(a[i]>a[1])
			k++;
	c=ceil(k*1.0/n);
	k=k%n;
	if(c%2==1){
		if(k==0) r=n;
		else r=k;
	}
	else{
		if(k==0) r=n;
		else r=n+1 -k;
	}
	cout<<c<<" "<<r;
	return 0;
}
