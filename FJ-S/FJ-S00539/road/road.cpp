#include<bits/stdc++.h>
using namespace std;
#define int long long
struct road{
	int u,v,w;
}r[700010];
int c[15];
int a[15][1000100];
bool cmp(road a,road b) {
	return a.w<b.w;
}
int fa[1000100];
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void join(int a,int b) {
	int aa=find(a),bb=find(b);
	fa[aa]=bb;
}
int p[15],ans;
bool vis[15];
int n,m,k;
void dfs(int nn,int step) {//枚举要城市化的 
	if(step>nn) {
		int pp=n+1;
		int anss=0;
		for(int i=1;i<=nn;i++) {
		//	cout<<p[i]<<"\n";
			anss+=c[p[i]];
		}
		int tot=m;
	//	memset(r,0,sizeof r);
	//	for(int i=1;i<=m;i++) {
	//		r[i]=r2[i];
	//	}
		for(int i=1;i<=nn;i++) {//加边 
			for(int j=1;j<=n;j++) {
				r[++tot].u=pp;
				r[tot].v=j;
				r[tot].w=a[p[i]][j];
				//cout<<pp<<" "<<j<<" "<<a[p[i]][j]<<"\n";
			}
			++pp;
		}
		sort(r+1,r+1+tot,cmp);
		//cout<<tot<<"\n";
		//for(int i=1;i<=tot;i++) {
		//	cout<<r[i].u<<" "<<r[i].v<<" "<<r[i].w<<"\n";
		//}
		for(int i=1;i<=pp;i++) {
			fa[i]=i;
		}
		for(int i=1;i<=tot;i++) {
			if(find(r[i].u)!=find(r[i].v)) {
				join(r[i].u,r[i].v);
				anss+=r[i].w;
		//		cout<<anss<<"\n";
			}
		}
		//cout<<anss<<"\n";
		ans=min(anss,ans);
		return ;
	}
	for(int i=1;i<=k;i++){
		if(!vis[i]) {
			p[step]=i;
			vis[i]=1;
			dfs(nn,step+1);
			vis[i]=0;
		}
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=1e9;
	bool maybe=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>r[i].u>>r[i].v>>r[i].w;
		//r2[i]=r[i];
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		if(c[i]) maybe=0;
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
			if(a[i][j]) maybe=0;
		}
	}
	if(maybe) {
		cout<<0;
		return 0;
	}
	if(k==0) {
		ans=0;
		sort(r+1,r+1+n,cmp);
		for(int i=1;i<=n;i++) {
			fa[i]=i;
		}
		for(int i=1;i<=m;i++) {
			if(find(r[i].u)!=find(r[i].v)) {
				join(r[i].u,r[i].v);
				ans+=r[i].w;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int j=1;j<=k;j++) {
		dfs(j,1);
	}
	cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
/*
4 3 2
1 3 2
1 4 3
3 4 4
1 9 9 9 1
2 2 2 2 2
*/
