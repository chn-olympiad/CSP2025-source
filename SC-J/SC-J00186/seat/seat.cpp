#include<bits/stdc++.h>
using namespace std;
int s[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	r=s[1];
	sort(s+1,s+1+n*m);
	int p=n*m+1-(lower_bound(s+1,s+1+n*m,r)-s);
	int h=ceil(1.0*p/n);
	if(p%n){
		if(h%2)cout<<h<<" "<<p%n;
		else cout<<h<<" "<<n+1-p%n;}
	else{
		if(h%2)cout<<h<<" "<<n;
		else cout<<h<<" "<<1;}
	return 0;}