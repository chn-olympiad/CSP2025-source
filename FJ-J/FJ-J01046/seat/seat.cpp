#include<bits/stdc++.h>
using namespace std;
int n,m,a[123],nth=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])nth++;
	}
	c=(nth-1)/n+1;
	r=nth%n;
	if(r==0){r=n;}
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
