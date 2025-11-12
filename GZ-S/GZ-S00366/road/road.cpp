#include <bits/stdc++.h>//GZ-S00366 都匀市第二中学 罗梓菡
using namespace std;

const int MAXN=1e4+1;
int n,m,k;
long long dist[MAXN],G[MAXN][MAXN],coun[11];
bool s[MAXN];

void DJ(int u){
	for(int i=1;i<=n+k;i++)
		dist[i]=1e9+1;
	for(int i=1;i<=n+k;i++)
		dist[i]=G[u][i];
	for(int i=1;i<=n+k;i++)
		cout<<dist[i]<<" ";
	G[1][1]=0;
	for(int i=1;i<=n+k;i++){
		if(dist[i]<1e9+1) s[i]=true;
		else s[i]=false;
	}
	s[1]=true;
	for(int i=1;i<=n+k;i++)
		cout<<s[i]<<" ";
	long long t,temp=1e9+1; 
	for(int i=1;i<=n+k;i++){
		if(i!=1 && !s[i] && i<=n){
			if(temp<G[u][i]){
				t=i;
				temp=G[u][i];
			}else if(i!=1 && !s[i] && i>n){
				if(temp<(G[u][i]+coun[i])){
					temp=G[u][i]+coun[i];
					t=i;
				}
			} 
		}
	}
	//if(t==u) continue;
	s[t]=true;
	for(int i=1;i<=n+k;i++){
		if(!s[i] && t<=n){
			if(dist[i]>(dist[t]+G[t][i]))
				dist[i]=dist[t]+G[t][i];
		}else if(!s[i] && t>n){
			if(dist[i]>(dist[t]+G[t][i])){
				dist[i]=dist[t]+G[t][i]+coun[i];
				coun[i]=0;
			}
		}
	}
	return ;
}
/*void inin(){
 	r=1;
 	cout<<2<<endl;
}*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u][v]=G[v][u]=w;
	}
	for(int i=m+1;i<=m+1+k;i++){
		cin>>coun[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			G[i][j]=G[j][i]=w;
		}
	}
	//cout<<r<<endl;
	DJ(1);
	//inin();
	//cout<<r<<endl;
	long long ans=1e9+1;
	for(int i=n;i<=n+k;i++){
		if(ans>dist[i])
			ans=dist[i];
	}
	cout<<ans<<endl;
	return 0;
}
