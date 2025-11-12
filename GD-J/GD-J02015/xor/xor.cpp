#include<bits/stdc++.h>
using namespace std;
long long f[500005],k,n,a[500005],a1[500005];
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a1[i]=a1[i-1]^a[i];
	}
	f[1]=(a[1]==k);
	for(long long i=2;i<=n;i++){
		for(long long j=i;j>=1;j--){
			long long ans=0;
			if(i-j+1==i){
				ans=a[i];
			}
			else{
				ans=a1[i-j]^a1[i];
			}
			f[i]=max(f[i],f[i-j]+(ans==k));
		}
	}
	cout<<f[n];
	return 0;
}
