#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[102],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("saet.out","w",stdout);
	cin>>n>>m>>x;
	a[1]=x;
	for(LL i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m);
	for(LL i=n*m;i>=1;i--){
		if(a[i]==x){
			x=n*m-i+1;
			break;
		}
	}
	LL r=x%m,c=x/n;
	if(r==0)r=m;
	if(r>0)c++;
	if(c%2==0)r=m-r+1;
	cout<<r<<" "<<c<<endl;
	return 0;
}
