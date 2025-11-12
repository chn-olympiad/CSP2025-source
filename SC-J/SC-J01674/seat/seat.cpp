#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[105];

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	int x=a[1],id=-1;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			id=n*m-i+1;
			break;
		}
	}
	int k=ceil(1.0*id/n);
	if(k%2==1){
		printf("%d %lld",k,(id+n-1)%n+1);
	}else{
		printf("%d %lld",k,n-(id+n-1)%n);
	}
	return 0;
}