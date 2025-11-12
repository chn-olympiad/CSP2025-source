#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fa[1001];
int father(ll now){
	if(fa[now]==now) return now;
	fa[now]=father(fa[now]);
	return fa[now];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k,dis[1001][1001],ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i; 
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=w;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=0x3f3f3f3f;
		}
	} 
	for(int kk=1;kk<=k;kk++){
		ll u;
		ll a[1001]={0};
		bool a1=0;
		cin>>u;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(ll i=1;i<=n-1;i++){
			for(ll j=i+1;j<=n;j++){
				ll sum=u+a[i]+a[j];
				if(a1==1) sum-=u;
				if(sum<dis[i][j]){
					dis[i][j]=sum;
					a1=1;
				}
			}
		}
	}
	for(ll i=1;i<=n-1;i++){
		for(ll j=i+1;j<=n;j++){
			ll t1=father(i);
			ll t2=father(j);
			if(t1!=t2){
				ans+=dis[i][j];
				fa[i]=j;
			}
		} 
	}
	cout<<ans;
	return 0;
}


