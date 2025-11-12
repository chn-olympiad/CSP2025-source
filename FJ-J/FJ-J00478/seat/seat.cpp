#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m,x,y,a[10001],b,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++){
		cin>>x;
		a[i]=-x;
	}
	x=-a[1];
	sort(a+1,a+n*m+1);
	for(LL i=1;i<=n*m;i++){
		if(-a[i]==x){
			y=i;
			break;
		}
	}
	b=y/n;
	c=y%n;
	if(b*n<y) b++;
	if(c==0){
		c=n;
	}
	if(b%2==0){
		c=n-c+1;
	}
	cout<<b<<" "<<c;
	return 0;
}
