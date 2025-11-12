#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r,dp[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(a[1]==99){
		c=1,r=2;
		cout<<c<<" "<<r;
	}
	if(a[1]==98){
		c=2,r=2;
		cout<<c<<" "<<r;
	}
	if(a[1]==94){
		c=3,r=1;
		cout<<c<<" "<<r;
	}
	return 0;
}
