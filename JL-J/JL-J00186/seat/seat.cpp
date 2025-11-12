#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
long long c[1000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,f;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	long long q=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		f=n*m+1-i;
		if(f%m!=0){
			c[f]=f/m+1;
		}else{
			c[f]=f/m;
		}
		if(c[f]%2==1){
			if(f%m!=0){
				b[f]=f%m;
			}else{
				b[f]=m;
			}
		}else{
			b[f]=m-(f-1)%m;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			printf("%lld %lld\n",c[n*m-i+1],b[n*m-i+1]);
			break;
		}
	}
	return 0;
}
