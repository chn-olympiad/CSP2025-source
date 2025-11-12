#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}p[1000001],t[10001],a[11][10001],h[1000001],tmp[1000001];
int n,m,k,f[10011],c[11],cnt,siz,x,y;
long long res,ans;
vector<int>u;
inline bool cmp(node _1,node _2){
	return _1.w<_2.w;
}
inline int find(int i){
	return f[i]==i?i:f[i]=find(f[i]);
}
inline void dfs(int i){
	if(i==k+1){
		siz=n-1;
		res=0;
		for(int j=1;j<=siz;j++){
			h[j]=t[j];
		}
		for(int j:u){
			res+=c[j];
			merge(h+1,h+siz+1,a[j]+1,a[j]+n+1,tmp+1,cmp);
			siz+=n;
			for(int l=1;l<=siz;l++){
				h[l]=tmp[l];
			}
		}
		for(int j=1;j<=n+k;j++){
			f[j]=j;
		}
		for(int j=1;j<=siz;j++){
			x=find(h[j].u);
			y=find(h[j].v);
			if(x!=y){
				f[x]=y;
				res+=h[j].w;
			}
		}
		ans=min(ans,res);
		return;
	}
	for(int j=i+1;j<=k+1;j++){
		if(j!=k+1){
			u.push_back(j);
		}
		dfs(j);
		if(j!=k+1){
			u.pop_back();
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++){
		x=find(p[i].u);
		y=find(p[i].v);
		if(x!=y){
			f[x]=y;
			cnt++;
			t[cnt]=p[i];
			ans+=p[i].w;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j].w;
			a[i][j].u=n+i;
			a[i][j].v=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	dfs(0);
	cout<<ans;
	return 0;
}
