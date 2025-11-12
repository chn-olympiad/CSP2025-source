#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll t,n,a[N][5],ans;
ll cnt[5],pos[N];
struct node{
	ll id,val;
}cha[N];
bool cmp(node s1,node s2){
	return s1.val<s2.val;
}

int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;

		for(ll i=1;i<=n;i++){
			cha[i].val=1e9;
		}		

		for(ll i=1;i<=n;i++){
			ll maxn=-1;
			for(ll j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>maxn){
					maxn=a[i][j];
					pos[i]=j;
				}
			}		
			ans+=maxn;
			cnt[pos[i]]++;
		}
		ll wz=-1;
		for(ll i=1;i<=3;i++){
			if(cnt[i]>n/2){
				wz=i;
			}
		}
		if(wz==-1){
			cout<<ans<<endl;
			continue;
		}
		ll num=cnt[wz]-n/2;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				if(j==pos[i]) continue;
				cha[i].val=min(cha[i].val,a[i][pos[i]]-a[i][j]);
				cha[i].id=i;
			}
		}
		sort(cha+1,cha+n+1,cmp);
		for(ll i=1;i<=n;i++){
			if(pos[cha[i].id]==wz){
				num--;
				ans-=cha[i].val;
			}
			if(num==0) break;
		}

		cout<<ans<<endl;
	}

	return 0;
}


/*
ulimit -s unlimited

Ren5Jie4Di4Ling5%
*/

/*
for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){//limit
				for(ll k=1;k<=3;k++){
					if(j==k){
						ll maxn=0;
						for(ll j1=1;j1<=3;j1++){
							if(j1==j) continue;
							for(ll k1=1;k1<=3;k1++){
								if(k1==j)continue;
								maxn=max(maxn,dp[i-1][j1][k1]);
							}
						}
						dp[i][j][k]=maxn+a[i][k];
					}else{
						ll maxn=0;
						for(ll k1=1;k1<=3;k1++){
							maxn=max(maxn,dp[i-1][j][k1]);
						}						
						dp[i][j][k]=maxn+a[i][k];
					}					
				}
			}
		}
		for(ll j=1;j<=3;j++){
			for(ll k=1;k<=3;k++){
				ans=max(ans,dp[n][j][k]);
			}
		}
		*/