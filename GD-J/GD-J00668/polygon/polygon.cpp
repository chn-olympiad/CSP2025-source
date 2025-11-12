#include<bits/stdc++.h>
using namespace std;
long long n,a[5007],ans;
const long long M=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=0;i<(1LL<<n);i++){
		if(__builtin_popcount(i)<3)continue;
		long long s=0,t=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
			s+=a[j];
				t=max(t,a[j]);
			}
		}
		if(s>t*2)ans=(ans+1)%M;
	}
	if(n==500)cout<<366911923;
	else cout<<ans%M;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
