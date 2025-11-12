#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int u,v,w,id;
	bool operator <(node o)const{
		return w<o.w;
	}
}a[2000010];

struct edge{
	int v,w;
};

int n,m,k,f[10010],fl,c[20],w[20][10010],used[20];

int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}

vector<edge> e[10020];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(!k){
		int ans=0;
		for(int i = 1;i <= n;i++) f[i]=i;
		for(int i = 1;i <= m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
		sort(a+1,a+m+1);
		for(int i = 1;i <= m;i++){
			int x=find(a[i].u),y=find(a[i].v);
			if(x!=y){
				f[y]=x;
				ans+=a[i].w;
			}
		}cout<<ans<<'\n';
		return 0;
	}
	int ans=0;
	for(int i = 1;i <= n;i++) f[i]=i;
	for(int i = 1;i <= m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i = 1;i <= k;i++){
		cin>>c[i];
		for(int j = 1;j <= n;j++)cin>>w[i][j];
	}
	for(int i = 1;i <= n;i++) for(int j = i+1;j <= n;j++){
		int minn=2e9+10,p=11;
		for(int l = 1;l <= k;l++) if(w[l][i]+w[l][j]<minn) minn=w[l][i]+w[l][j],p=l;
		a[++m]={i,j,minn+c[p],p};
	}
	sort(a+1,a+m+1);
	for(int i = 1;i <= m;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x!=y){
			f[y]=x;
			if(used[a[i].id])ans+=a[i].w-c[a[i].id];
			else ans+=a[i].w;
			used[a[i].id]=1;
		}
	}cout<<ans<<'\n';
	return 0;
}

