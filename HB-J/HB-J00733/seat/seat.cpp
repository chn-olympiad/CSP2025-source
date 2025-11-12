#include<bits/stdc++.h>
using namespace std;
int t,no;
int n,m,s=1;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>t;
	for(int i=2;i<=n*m;i++){
		cin>>no;
		if(no>t)s++;
	}
	c=ceil(s*1.0/n);
    r=s%n;
	if(r==0)r=n;
	if(c%2==0){
		if(r!=0)r=n+1-r;
	}
	cout<<c<<" "<<r;
	return 0;
}

