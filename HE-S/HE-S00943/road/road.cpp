#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=10005;
ll n,m,k,c,u,v,ans,w;
ll maxV=pow(10,9)+1;
ll a[N][N],dis[N];
bool vis[N];
void prim(){
	for(ll i=2;i<=n;i++){
		ll minV=maxV,used=0;
		for(ll j=2;j<=n;j++){
			if(!vis[j]&&dis[j]<minV){
				minV=dis[j];
				used=j;
			}
		}
		vis[used]=1;
		for(ll j=1;j<=n;j++){
			if(!vis[j]&&a[used][j]<maxV&&dis[j]>a[used][j]){
			    dis[j]=a[used][j];
			}    
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j)a[i][j]=0;
			else a[i][j]=maxV;
		}
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u][v]=w;a[v][u]=w;
	}
	for(ll i=1;i<=n;i++)dis[i]=a[1][i];
	vis[1]=1;
	prim();
	for(ll i=1;i<=n;i++)ans=ans+dis[i];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

