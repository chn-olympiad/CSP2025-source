#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],k,p,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			p=n*m-i+1;
		}
	}
	c=int(p*1.0/n+0.999);
	if(c%2==1)
	{
		r=(p-1)%n+1;
	}
	else{
		r=c*n-p+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
