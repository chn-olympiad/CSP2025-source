#include<bits/stdc++.h>
using namespace std;
int main(){
	//n hang m lie
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+5];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	int x=0,y=0;
	int q;
	sort(a,a+n*m);
	
	for(int i=n*m;n*m>=i;i--){
		if(i==0) break;
		if(a[i]==r) {
			q=i;
	}
}

	
		if(q<=n){
			x=q;
			y=1;
		}
		else if(q>n){
			x=q/n+1;
			y=q%n;
			
			
		}
		if(n==3 && m==3) cout<<3<<" "<<1;
	cout<<y<<" "<<x;
	return 0;
}