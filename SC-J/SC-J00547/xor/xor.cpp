#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,now=0,ans=0;
const int ii=5e5+5;
ll a[ii];
bool f(ll l,ll r){
	if((a[r]^a[l-1])==k) return 1;
	return 0; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]^=a[i-1];
		for(int j=i;j>0;j--){
			if(f(j,i)){
				if(j>now){
					ans++;
					now=i;
				}
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}