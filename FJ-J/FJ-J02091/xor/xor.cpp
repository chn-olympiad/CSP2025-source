#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long len=1;len<n;len++){
		bool p=1;
		for(long long l=1;l+len<=n;l+=len){
			long long r=l+len,sum=0;
			if(r>n){
				r=n;
			}
			for(long long k=l;k<=r;k++){
				sum^=a[k];
			}
			if(sum!=k){
				p=0;
				break;
			}
		}
		if(p==1){
			long long ans=n/len+bool(n%len);
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
