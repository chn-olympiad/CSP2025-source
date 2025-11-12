#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100010][10],flbb,flcc;
ll aa[100010],ans;
priority_queue<pair<ll,ll>> ab,ba; 
bool cmp(ll a,ll b){
	return a>b;
}
ll dfs(ll aa,ll bb,ll cc,ll i,ll tot){
//	cout<<aa<<" "<<bb<<" "<<cc<<" "<<i<<" "<<tot<<endl;
	if(aa>(n/2)||bb>(n/2)||cc>(n/2)){
		return 0;
	}if(i>n){
		return tot;
	}else{
		return max(dfs(aa+1,bb,cc,i+1,tot+a[i][1]),max(dfs(aa,bb+1,cc,i+1,tot+a[i][2]),dfs(aa,bb,cc+1,i+1,tot+a[i][3])));
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		if(!flbb&&!flcc){
			for(ll i=1;i<=n;i++){
				aa[i]=a[i][1];
			}
			sort(aa+1,aa+n+1,cmp);
			for(ll i=1;i<=n/2;i++){
				ans+=aa[i];
			}
			cout<<ans<<endl;
		}
		else if(!flcc){
			ll aaa=0,bbb=0;
			for(ll i=1;i<=n;i++){
				if(a[i][1]>=a[i][2]){
					if(aaa<n/2){
						aaa++;
						ans+=a[i][1];
						ab.push(make_pair(a[i][2],i));
					}else{
						pair<ll,ll> axa=ab.top();
						if(axa.first+a[i][1]>a[axa.second][1]+a[i][2]||((axa.first+a[i][1]==a[axa.second][1]+a[i][2])&&axa.first<a[i][2])){
							ab.pop();
							ans+=axa.first+a[i][1];
							ans-=a[axa.second][1];
							ab.push(make_pair(a[i][2],i));
						}else{
							bbb++;
							ans+=a[i][2];
							ba.push(make_pair(a[i][1],i));
						}
					}
				}else{
					if(bbb<n/2){
						bbb++;
						ans+=a[i][2];
						ba.push(make_pair(a[i][1],i));
					}else{
						pair<ll,ll> axa=ba.top();
						if(axa.first+a[i][2]>a[axa.second][2]+a[i][1]||((axa.first+a[i][2]==a[axa.second][2]+a[i][1])&&axa.first<a[i][1])){
							ba.pop();
							ans+=axa.first+a[i][2];
							ans-=a[axa.second][2];
							ba.push(make_pair(a[i][1],i));
						}else{
							aaa++;
							ans+=a[i][1];
							ab.push(make_pair(a[i][2],i));
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
		else{
			printf("%lld\n",max(dfs(1,0,0,2,a[1][1]),max(dfs(0,1,0,2,a[1][2]),dfs(0,0,1,2,a[1][3]))));
		}
		
	}
	return 0;
}
