#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	long long n,k,a[500003],b[500003],m=0,i,n1=1;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)scanf("%lld",&a[i]),b[i]=a[i];
	if(k==0)for(i=0;i<n;i++)if(a[i]==0)m++;
	if(k==1)for(i=0;i<n;i++)if(a[i]==1)m++;
	if(k>1){
		for(;n1<n;){
			if(b[i]==k)m++;
			for(i=n1;i<n&&b[i]!=k;b[i]=b[i]^b[i-1],i++);
			if(i<n)m++,n1=i;
		}
	}
	printf("%lld",m);
	return 0;
}
