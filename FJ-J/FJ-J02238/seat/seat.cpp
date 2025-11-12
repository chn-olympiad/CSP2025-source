#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,c,r,id;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	cnt=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
		if(a[i]==cnt){
			id=n*m-i+1;
			break;
		}
	c=ceil(id*1.0/n);
	r=id-(c-1)*n;
	if(c&1)cout<<c<<" "<<r;
	else cout<<c<<" "<<n-r+1;
	return 0;
}
