#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	long long v,w;
};
vector<node>a[1100006];
long long b[10044][15],c[15],v[10005],v1[10005],v2[15],l[10005],ans;
void d(){
	
	memset(l,0x3f3f,sizeof(l));
	l[1]=0;
	while(1){
		int u=0;
		for(int i=1;i<=n;i++){
			if(v[i]==0&&l[u]>l[i])u=i;
		}		
		if(u==0)return;
		if(v1[u]!=0){
			ans+=c[v1[u]];
			
		}
		ans+=l[u];
		v[u]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(l[i]>b[i][j]+b[u][j]+int(v2[j]==0)*c[j]){
					if(v2[j]!=1)v1[i]=j,v2[j]=1;;
					l[i]=b[i][j]+b[u][j];
				}
			}
		}
		for(int i=0;i<a[u].size();i++){
			l[a[u][i].v]=min(l[a[u][i].v],a[u][i].w);
		}
		//for(int i=1;i<=n;i++)cout<<l[i]<<' ';
		//cout<<endl; 
		///for(int i=1;i<=n;i++)cout<<v[i]<<' ';
		//cout<<endl; 
	}
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[j][i];
		}
	}
	d();
	cout<<ans; 
	return 0;
}

