#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],RP=0,cnt=0,maxn=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if((j-i+1)>=3){
				for(ll k=i;k<=j;k++){
					cnt+=a[k];
					maxn=max(maxn,a[k]);
				}
				if(cnt>(2*maxn)){
					RP++;
				}
			}
			cnt=0;
			maxn=0;
		}
	}
	printf("%lld",RP);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
