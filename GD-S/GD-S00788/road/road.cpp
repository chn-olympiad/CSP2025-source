#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
int f[18888];
int mp[1001][1001];
struct abc{
	int u;
	int v;
	int w;
}a[1000086];
bool cmp(abc a,abc b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mp[i][j]=-1;
	int in;
	for(int i=1;i<=k;i++){
		cin>>in;
		for(int j=1;j<=n;j++){
			cin>>in;
		}
	}
	if(k==0){
		int cnt=0;
		sort(a+1,a+m+1,cmp);
		for(int i=1,fx,fy;i<=m&&cnt<n-1;i++){
			fx=find(a[i].u),fy=find(a[i].v);
			if(fx==fy) continue;
			if(fx>fy) swap(fx,fy);
			f[fy]=fx;
			ans+=a[i].w;
			cnt++;
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=m;i++){
			if(a[i].w<mp[a[i].u][a[i].v]||mp[a[i].u][a[i].v]==-1) mp[a[i].u][a[i].v]=in;
		}
		m=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(mp[i][j]!=-1) m++,a[m].u=1,a[m].v=j,a[m].w=mp[i][j];
		sort(a+1,a+m+1,cmp);
		int cnt=0;
		for(int i=1,fx,fy;i<=m&&cnt<n-1;i++){
			fx=find(a[i].u),fy=find(a[i].v);
			if(fx==fy) continue;
			if(fx>fy) swap(fx,fy);
			f[fy]=fx;
			ans+=a[i].w;
			cnt++;
		}
		cout<<ans;
	}
	return 0;
}

