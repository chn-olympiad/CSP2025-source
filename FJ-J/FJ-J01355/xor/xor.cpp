#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans;
bool fla=1,flb=1,flc=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) fla=0;
		if(a[i]>=2) flb=0;
	}
	if(fla&&k==0){
		cout<<n/2;
		return 0;
	}
	if(flb){
		long long cnt=0;
		if(k==0){
			for(long long i=1;i<=n;i++){
				if(a[i]==1) cnt++;
				else{
					ans++;
					ans+=cnt/2;
					cnt=0;
				}
			}
		}
		if(k==1){
			for(long long i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==k) ans++;
	}
	cout<<ans;
	return 0;
}
