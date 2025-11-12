#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,k,a[N],f[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll len=1;len<=n;len++){
		for(ll r=len;r<=n;r++){
			ll l=r-len+1;
			ll sumxor=0,ok=0;
			for(ll i=l;i<=r;i++){
				sumxor^=a[i];
				if(f[i]==1){
					ok=1;
				}
			}
			if(sumxor==k&&ok==0){
				ans++;
				for(ll i=l;i<=r;i++){
					f[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
