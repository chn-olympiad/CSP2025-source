#include<bits/stdc++.h>
using namespace std;
int a[110],c,r;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1],_i;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s)_i=i;
	}_i=n*m-_i+1;
	if(_i%n==0)c=_i/m;
	else c=_i/m+1;
	r=_i%n;
	if(r==0)r+=n;
	if(c%2==0)r=n-r+1;
	cout<<c<<' '<<r;
	return 0;
}
