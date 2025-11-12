#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e4+100;
ll mp[maxn][maxn],n,m,k,cun[20][20],path[maxn][maxn],vis[maxn],ji,ans;
void floyd(){
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll w=1;w<=n;w++){
				if(i!=j && j!=w && i!=w && path[i][j] && path[j][w] && path[i][w]){
					path[j][w]=min(path[j][w],path[j][i]+path[i][w]);
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	for(ll j=1;j<=k;j++){
		ll c;
		cin>>c;
		for(ll i=1;i<=n;i++){
			cin>>cun[j][i];
			cun[i][j]=cun[j][i];
		}
		for(ll mu=1;mu<=n;mu++){
			for(ll shi=1;shi<=n;shi++){
				if(cun[shi][j]+cun[j][mu]<mp[shi][mu])mp[shi][mu]=cun[shi][j]+cun[j][mu];
				
			}
		}
	}
	floyd();
	for(ll i=1;i<=n;i++){
		ll temp=INT_MAX;
		for(ll j=1;j<=n;j++){
			if(vis[i])continue;
			if(path[i][j]>temp)ji=j;
			temp=min(temp,path[i][j]);
			
		}
		ans+=temp;
		vis[ji]=1;
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
