#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=1e2+10;
LL n,m,a[N],c[N][N];
bool cmp(const LL &x,const LL &y){return x>y;}
int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	LL tmp=n*m;
	for(LL i=1;i<=tmp;i++) scanf("%lld",&a[i]);
	LL x=a[1];
	sort(a+1,a+tmp+1,cmp);
	LL minl=1;
	LL minh=1;
	LL maxh=n;
	LL idx=0;
	while(true){
		for(LL i=minh;i<=maxh;i++) c[i][minl]=a[++idx];
		if(idx==tmp) break;
		minl++;
		for(LL i=maxh;i>=minh;i--) c[i][minl]=a[++idx];
		if(idx==tmp) break;
		minl++;
	}
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			if(x==c[i][j]){
				printf("%lld %lld",j,i);
				return 0;
			}
		}
	}
	return 0;
}
