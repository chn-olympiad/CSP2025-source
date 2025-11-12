#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;scanf("%lld %lld",&n,&k);
	for(long long i=1;i<=n;i++){
		long long t;scanf("%lld",&t);
		a[i]=a[i-1]^t;
//		cout<<a[i]<<" ";
	}
	long long z=1;
	for(long long i=1;i<=n;i++){
		
		for(long long j=z;j<=i;j++){
			if((a[i]^a[j-1])==k){
				z=i+1,ans++;
//				cout<<i<<" "<<j<<" "<<(a[i]^a[j-1])<<'\n';
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
