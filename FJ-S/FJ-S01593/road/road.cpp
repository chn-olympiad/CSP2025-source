#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
const int N=2e4+5,M=1e6+5,K=15;
int n,m,k,c[K],fa[N],ans=1e18,x[K];
pii a[K][N];
int find(int x) {
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
struct edge {
	int u,v,w;
} e[M];
bool cmp(edge a,edge b) {
	return a.w<b.w;
}
bool us[K];
void dfs(int now) {
	if(now>k) {
		int num=n;
		for(int i=1; i<=k; i++) {
			if(us[i])
				num++;
		}
		for(int i=1; i<=n+k; i++)
			fa[i]=i;
		for(int i=0; i<=k; i++)
			x[i]=1;
		int cnt=0,i=1,sum=0;
//		for(int i=1; i<=k; i++)
//			cout<<us[i]<<' ';
		while(cnt<num-1) {
			int nowi=e[x[0]].w,id=0;
			if(x[0]>m)
				nowi=1e18;
			for(int j=1; j<=k; j++) {
				if(x[j]>n)
					continue;
				if(!us[j])
					continue;
				int nowj=a[j][x[j]].fs;
				if(x[j]==1)
					nowj+=c[j];
//				cout<<j<<' '<<nowj<<'\n';
				if(nowj<=nowi)
					nowi=nowj,id=j;
			}
			int u=id+n,v=a[id][x[id]].sc,w=nowi;
			if(id==0)
				u=e[x[0]].u,v=e[x[0]].v;
			x[id]++;
//			cout<<id<<' '<<x[id]<<' ';
			int fu=find(u),fv=find(v);
			if(fu!=fv) {
				sum+=w;
				fa[fu]=fv;
				cnt++;
//				cout<<"ADD "<<u<<' '<<v<<' '<<w<<'\n';
				if(cnt==num-1)
					break;
			}
		}

//		cout<<sum<<'\n';
		ans=min(ans,sum);
		return;
	}
	us[now]=1;
	dfs(now+1);
	us[now]=0;
	dfs(now+1);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1; i<=n; i++)
		fa[i]=i;
//	for(int i=1; i<=m; i++) {
//		int fu=find(e[i].u),fv=find(e[i].v);
//		if(fu!=fv) {
//			ans+=e[i].w;
//			fa[fu]=fv;
//			v.pb(e[i]);
//		}
//	}
	for(int t=1; t<=k; t++) {
		cin>>c[t];
		for(int i=1; i<=n; i++)
			cin>>a[t][i].fs,a[t][i].sc=i;
		sort(a[t]+1,a[t]+n+1);
	}
	dfs(1);
	cout<<ans;
	return 0;
}

