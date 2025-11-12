#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=505;
int a[MAXN],n,m,cnt;
int h,l;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
		if(i!=1){
			if(a[i]>a[1]){
				cnt++;
			}
		}
	}
	cnt++;
	h=(cnt-1)/n+1;
	cnt%=(2*n);
	if(cnt>n){
		cnt-=n;
		l=n-cnt+1;
	}
	else l=cnt;
	printf("%lld %lld",h,l);
	return 0;
}
