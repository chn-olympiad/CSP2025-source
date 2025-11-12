#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
const int N=1e4+25,M=1e6+25;
int n,m,K,fa[N],siz[N],c[11],L[11];
struct yes{
	int x,y,z;
}a[M],b[N];
bool cmp(yes x,yes y){
	return x.z<y.z;
}
struct edge{
	int v,w;
}d[11][N];
bool cmp2(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+1+m,cmp);
	long long ans=0;
	int ct=0;
	for(int i=1;i<=m;i++){
		int x=find(a[i].x),y=find(a[i].y);
		if(x!=y){
			ans+=a[i].z;
			b[++ct]=a[i];
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y;
			siz[y]+=siz[x];
		}
	}
	bool fg=1;
	for(int i=0;i<K;i++){
		cin>>c[i];
		if(c[i])fg=0;
		for(int j=1;j<=n;j++){
			cin>>d[i][j].w;
			d[i][j].v=j;
		}
		sort(d[i]+1,d[i]+1+n,cmp2);
	}
	priority_queue<pi,vector<pi>,greater<pi>>q;
	for(int i=(1<<K)-1;i>=0;i--){
		long long as=0;
		for(int j=1;j<=n+K;j++){
			fa[j]=j;
			siz[j]=1;
		}
		int l=1,ab=0;
		q.push({b[1].z,-1});
		for(int j=0;j<K;j++)
			if(i>>j&1){
				L[j]=1;
				q.push({d[j][1].w,j});
				as+=c[j];
				ab++;	
			}
		int now=n-1+ab;
		while(now&&!q.empty()){
			pi up=q.top();
			q.pop();
			int u=up.second,x,y;
			if(u==-1){
				x=find(b[l].x);
				y=find(b[l].y);
			}
			else{
				x=find(n+u+1);
				y=find(d[u][L[u]].v);
			}
			if(x!=y){
				as+=up.first;
				now--;
				if(siz[x]>siz[y])swap(x,y);
				fa[x]=y;
				siz[y]+=siz[x];
			}
			if(u==-1){
				if(++l<n)q.push({b[l].z,-1});
			}
			else if(++L[u]<=n)q.push({d[u][L[u]].w,u});
		}
		while(!q.empty())q.pop();
		ans=min(ans,as);
		if(fg)break;
	}
	cout<<ans;
	return 0;
}
