#include<bits/stdc++.h>
using namespace std;
int n,m,a,pm=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1,x;i<n*m;i++){
		cin>>x;	
		if(x>a) pm++;
	}
	c=ceil(pm*1./m);
	r=pm%n;
	if(r==0) r=n;
	if(c%2==0) r=n-r+1;
	cout<<c<<" "<<r;
	return 0;
}
