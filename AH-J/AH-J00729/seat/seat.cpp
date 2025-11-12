#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[110],tot,A;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=n;j++){
			scanf("%lld",&a[++tot]);
			if(i==1&&j==1) A=a[tot];
		}
	}
	sort(a+1,a+tot+1);
	LL x=1,y=1;
	for(LL i=tot;i>=1;i--){
		if(a[i]==A){
			printf("%lld %lld",y,x);
			return 0;
		}
		if(x==n&&(y&1)) y++;
		else if(x==1&&!(y&1)) y++;
		else if(y&1) x++;
		else x--;
	}
	return 0;
}
