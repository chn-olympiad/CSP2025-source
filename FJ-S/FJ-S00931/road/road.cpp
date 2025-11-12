#include <bits/stdc++.h>
using namespace std;

int fa[10001],c[11],a[11][10001],at[11];

struct node{
	int u,v,w;
};
vector<node>s;
bool mp[11],f[11];

bool cmp(node,node);
int find(int);

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		s.push_back({u,v,w});
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]=0)
			cnt++;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(s.begin(),s.end(),cmp);
	for(node &x:s){
		int &u=x.u,&v=x.v,&w=x.w;
	}
	for(node x:s){
		int u=x.u,v=x.v,w=x.w;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			for(int i=1;i<=k;i++)
				if(a[i][u]+a[i][v]<w)
					w=a[i][u]+a[i][v];
			ans+=w;
		}
	}
	cout<<ans<<endl;
	return 0;
}

inline bool cmp(node a,node b){
	return a.w<b.w;
}

inline find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
