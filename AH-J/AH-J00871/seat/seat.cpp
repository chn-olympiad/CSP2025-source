#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e3+10;
LL a[N];
LL n,m,R;
bool cmp(const LL &x,const LL &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&R);
	for(LL i=1;i<n*m;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n*m,cmp);
	LL pos=-1;
	for(LL i=1;i<n*m;i++){
		if(a[i]<R){
			pos=i;
			break;
		}
	}
	if(pos==-1) pos=n*m;
	LL r=0,c=0;
	r=pos%n;
	c=pos/n;
	if(r==0) printf("%lld ",c);
	else printf("%lld ",c+1);
	if(r==0){
		printf("%lld",n);
		return 0;
	}
	if(c%2==0) printf("%lld ",r);
	else printf("%lld ",n-r+1);
	return 0;
}
