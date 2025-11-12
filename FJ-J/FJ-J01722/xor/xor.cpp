#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;typedef int t;typedef long long ll;
ll n,k,a[500086],ass,tp,tpass;
t main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(t i=1;i<=n;i++)scanf("%d",&a[i]);
	for(t i=1;i<=n;i++){
		tp=a[i];
		for(t j=i;j<=n;j++){
			tpass=0;
			if(i==j&&a[j]==k)ass++;continue;
			for(t l=i+1;l<=j;l++){
				tp^=a[l];
				tpass+=tp;
			}if(tpass==k)ass++;
		}
	}printf("%lld",ass);
	return 0;
}
