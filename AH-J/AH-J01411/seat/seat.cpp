#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
using LL=long long;
const LL N=1e2+5;
LL n,m,c,a[N];
bool cmp(const LL &x,const LL &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++) cin>>a[i];
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	LL pos;
	for(LL i=1;i<=n*m;i++) if(a[i]==c) pos=i;
	cout<<pos/n+(pos%n!=0)<<" ";
	if((pos/n+(pos%n!=0))%2==0) cout<<n-(pos%n)+(pos%n!=0);
	if((pos/n+(pos%n!=0))%2!=0) cout<<1+(pos%n!=0)+1;
	return 0;
}
