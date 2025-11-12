#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,x,w,ct,c,r;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++) cin>>a[i];		
	x=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==x) w=i;
	}
	ct=n*m-w;
	if(ct%n>=1){
		c=ct/n+1;
		if(ct/n%2==1) r=n+1-ct%n;
		else r=ct%n;
	}
	else{
		c=ct/n;
		if(c%2==1) r=n;
		else r=1;
	}
	cout<<c<<" "<<r;
	return 0;
}
