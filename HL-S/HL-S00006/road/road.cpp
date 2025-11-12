#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m,k;
map<ll,map<ll,ll> >a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}for(int i=1;i<=k;i++){
		ll s,t[10005];
		cin>>s;
		for(int k=1;k<=n;k++)cin>>t[k];
		for(int k=1;k<n;k++){
			for(int j=k+1;j<=n;j++){
				if(a[k][j]==0)a[k][j]=a[j][k]=s+t[k]+t[j];
				else a[k][j]=a[j][k]=min(a[k][j],s+t[k]+t[j]);
			}
		}
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++){
				a[i][j]=a[j][i]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}ll ans=0,f=1,i=1;
	bool vis[10001]={};
	while(f<n){
		vis[i]=1;
		ll p,q=1e9;
		for(int j=1;j<=n;j++){
			if(q>=a[i][j]&&j!=i&&vis[j]==0){
				q=a[i][j];
				p=j;
			}
		}ans+=q;
		i=p;
		f++;
	}cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}cout<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
------
13


*/

