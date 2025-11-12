#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],p,c,r,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+m*n);
	reverse(a+1,a+1+m*n);
	for(int i=1;i<=m*n;i++){
		if(a[i]==p){s=i;break;}
	}
	if(s%n==0)c=s/n;
	else c=s/n+1;
	int d=s%(2*n);
	if(d<=n)r=d;
	else r=n-(d%n-1);
	cout<<c<<' '<<r;
	return 0;
}