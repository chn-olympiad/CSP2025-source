#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,m,k;
struct node{
	ll x,y,z;
};
bool cmp(const node&a,const node&b){
	return a.z<b.z;
}
node G[N];
ll c[N],pos[N],g[N][N];
int f[N];
ll minn=0;
int find(int x){
	if(x!=f[x])f[x]=find(x);
	return f[x];
}
void dfs(int x,int t){
	ll res=0;
	if(x==k){
		int cnt=0;
		for(int i=1;i<=k;i++)
			if(t&(1<<(i-1))){
				for(int j=1;j<=n;j++){
					G[++cnt].x=i+n;
					G[cnt].y=j;
					G[cnt].z=g[i+n][j];
				}
				res+=c[i];
			}	
		sort(G+1,G+1+cnt,cmp);
		for(int i=1;i<=n+k;i++)f[i]=i;
		int K=0,i=1,j=1;
		while(K<n+k&&i<=m&&j<=cnt){
			int Fa=find(G[i].x),Fb=find(G[i].y);
			if(Fa==Fb){
				i++;
				continue;
			}
			int Fa2=find(G[j].x),Fb2=find(G[j].y);
			if(Fa2==Fb2){
				i++;
				continue;
			}
			if(G[i].z>G[j].z){
				res+=G[j].z;
				j++;
				f[Fa2]=Fb2;
			}else{
				res+=G[j].z;
				f[Fa]=Fb;
				i++;
			}
			K++;
			if(res<=minn)return;
		}
	}
	dfs(x+1,t);
	dfs(x+1,t|(1<<(x+1)));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int cnt=m;
	for(int i=1;i<=m;i++)cin>>G[i].x>>G[i].y>>G[i].z;
	sort(G+1,G+1+m,cmp);
	ll low=-0x3f3f3f3f,lowc=-0x3f3f3f3f;
	for(int i=1;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			scanf("%lld",g[i+n][j]);
			if(g[i+n][j]<low){
				low=g[i+n][j];
				pos[i]=j;
			}
			g[i+n][pos[i]]+=c[i];
			lowc=min(lowc,c[i]);
		}
	}
	dfs(1,0);
//	cout<<lowc<<"\n";
	cout<<minn;
	return 0;
}

