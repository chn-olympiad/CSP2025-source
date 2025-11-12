#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000+10;
const int mod = 998244353;
ll n;
ll a[maxn];
ll ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll maxa = 0;
	for(int i =1;i<=n;++i){
		cin>>a[i];
		maxa = max(a[i],maxa);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n == 3){
		ll sum = 0;
		for(int i = 1;i<=n;++i){
			sum+=a[i];
		}
		if(sum>2*maxa){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
		return 0;
	}
	else{
		for(int i = 1;i<=n;++i){
			for(int j = i;j<=n;++j){
				for(int l = j;l<=n;++l){
					int c = j-i;
					if(c>=3){
						ll maxdist = 0,sum = 0;
						for(int k = i;k<=j;++k){
							maxdist = max(maxdist,a[k]);
							sum+=a[k];
						}
						if(sum>2*maxdist){
							ans = (ans+1)%mod;
						}
					}
				}
				
			}
		}
		cout<<ans;
	}
	return 0;
}