#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+15,M=1e6+5,K=15;
struct node{
	int x,y,z;
}e[M],g[M];
bool cmp(node x,node y){
	return x.z<y.z;
}
int a[K][N],fa[N],c[K];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;
	ll ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int tot=0;
	for(int i=1;i<=m;i++){
		int x=find(e[i].x),y=find(e[i].y);
		if(x==y)continue;
		fa[x]=y;
		ans+=1ll*e[i].z;
		tot++;
		g[tot]=e[i];
		if(tot==n-1)break;
	}
	for(int s=0;s<(1<<k);s++){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			if(i<n){
				e[i]=g[i];
			}
		}
		int cnt=n,len=n-1;
		ll res=0;
		for(int i=1;i<=k;i++){
			int h=(s>>(i-1))&1;
			if(h){
				res+=1ll*c[i];
				cnt++;
				fa[n+i]=n+i;
				for(int j=1;j<=n;j++){
					e[++len]={n+i,j,a[i][j]};
				}
			}
		}
		sort(e+1,e+1+len,cmp);
		tot=0;
		for(int i=1;i<=len;i++){
			int x=find(e[i].x),y=find(e[i].y);
			if(x==y)continue;
			fa[x]=y;
			res+=1ll*e[i].z;
			tot++;
			if(tot==cnt-1)break;
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}
