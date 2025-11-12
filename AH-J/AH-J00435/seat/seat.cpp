#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[105],k,id;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	k=a[1];
	sort(a+1,a+n*m+1);
	for(LL i=n*m;i>=1;i--)
		if(a[i]==k) id=n*m-i+1;
	LL g=(id-1)/n;
	printf("%lld ",g+1);
	if(g%2==0) printf("%lld",id-g*n);
	else printf("%lld",n-(id-g*n)+1);
	return 0;
}
