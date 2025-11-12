#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[5005];
void Try_30(){
	LL x=a[1],y=a[2],z=a[3];
	LL f=max(max(x,y),z);
	if(x+y+z>f*2) printf("1");
	else printf("0");
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==3) Try_30();
	return 0;
}
