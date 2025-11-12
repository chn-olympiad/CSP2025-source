#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a1[100005],a2[100005],a3[100005],tot1[100005],tot2[100005],tot3[100005];
ll f[100005];
bool cmp(ll a,ll b){
	return a>b;
	}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		for(ll i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			tot1[a1[i]]=i;
			tot2[a2[i]]=i;
			tot3[a3[i]]=i;
			}
		sort(a1+1,a1+n+1,cmp);
		sort(a2+1,a2+n+1,cmp);
		sort(a3+1,a3+n+1,cmp);
		ll maxn=-1;
		for(ll i=(n>2?1:0);i<=n/2;i++){
			ll k=n-i;
			for(ll j=1;j<=(k>1?k-1:k);j++){
				ll l=k-j;
				ll ans=0;
				//cout<<i<<' '<<j<<' '<<l<<endl;
				for(ll o=1;o<=i;o++){
					ans+=a1[o];
					//cout<<ans<<endl;
					}
				for(ll o=1;o<=j;o++){
					ans+=a2[o];
					//cout<<ans<<endl;
					}
				for(ll o=1;o<=l;o++){
					ans+=a3[o];
					//cout<<ans<<endl;
					}
				maxn=max(maxn,ans);
				}
			}
			cout<<maxn<<endl;
		}
	return 0;
	}
