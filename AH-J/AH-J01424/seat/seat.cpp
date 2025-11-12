#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
using LL =long long;
const LL N = 1e2+3;

LL n,m,a[N],ans[N][N],s;
bool cmp(const LL &x,const LL &y){
	return x>y;
}

int main(){
	freopen("seat.in","r,",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n*m;i++)scanf("%lld",&a[i]);
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	LL r=1,c=1;
	char dri='D';
	for(LL i=1;i<=n*m;i++){
		ans[r][c]=a[i];
		if(ans[r][c]==s){
			printf("%lld %lld",c,r);
			break;
		}
		if(dri=='D'&&r==n) c++,dri='U';
		else if(dri=='U'&&r==1)c++,dri='D';
		else if(dri=='D') r++;
		else if(dri=='U') r--;
	}
	return 0;
}
