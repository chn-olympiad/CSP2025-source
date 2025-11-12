#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e6;
ll t,n,a[maxn][4],v[maxn];
vector<ll>b[7][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ll ans=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			ll op=0,x=0;
			for(ll j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if(x<a[i][j]){
					x=a[i][j];
					op=j;
				}
			}
			b[t][op].push_back(i);
		}
		for(ll k=1;k<=3;k++){
			for(ll i=0;i<b[t][k].size();i++){
				ans+=a[b[t][k][i]][k];
			}
		}
		//cout<<ans<<endl;
		for(ll k=1;k<=3;k++){
			ll s=b[t][k].size();
			if(s>n/2){
				for(ll i=0;i<s;i++){
					v[i]=1e18;
					for(ll j=1;j<=3;j++){
						if(j!=k){
							v[i]=min(v[i],a[b[t][k][i]][k]-a[b[t][k][i]][j]);
						}
					}
				}
				sort(v,v+s);
				for(ll i=0;i<s-n/2;i++){
					ans-=v[i];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1



1
2
10 9 8
4 0 0*/
