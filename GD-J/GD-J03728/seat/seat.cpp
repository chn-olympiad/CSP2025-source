#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,a[105],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n*m;i++)scanf("%lld",&a[i]);
	b=a[1];
	sort(a+1,a+n*m+1);
	for(i=1,j=1,k=n*m;;k--){
		if(a[k]==b){
			printf("%lld %lld",i,j);
			return 0;
		}
		if(i%2==1){
			j++;
			if(j==n+1)i++,j=n;
		}else{
			j--;
			if(j==0)i++,j=1;
		}
	}
	return 0;
}
