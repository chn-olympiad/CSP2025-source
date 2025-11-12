
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k,v[N];
struct edge{
	int x,y,val;
}a[M],b[K][N],z[N*K];
bool e_vis[M];
bool cmp(edge x,edge y){
	return x.val<y.val;
}
int f[N+K],sz[N+K];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void _union(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		if(sz[x]<sz[y]){
			f[x]=y;
			sz[y]+=sz[x];
		}else{
			f[y]=x;
			sz[x]+=sz[y];
		}
	}
}
void clear(){
	for(int i=1;i<=n+k;i++){
		f[i]=i;
		sz[i]=1;
	}
}
ll ans=0x3f3f3f3f3f3f3f3f;
bool vis[K];
void dfs(int x){
	if(x==k+1){
	clear();
		int sz=0;
		ll sum=0;
		priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >q;
		for(int i=1;i<=k;i++){
			if(vis[i]){
				sum+=v[i];
//				cerr<<i<<' ';
				q.push({b[i][1].val,make_pair(i,1)});
			}
		}
//		cerr<<'\n';
		while(!q.empty()){
			auto tp=q.top().second;q.pop();
			z[++sz]=b[tp.first][tp.second];
//			cerr<<tp.first<<' '<<tp.second<<' '<<b[tp.first][tp.second].val<<'\n';
			if(tp.second==n){
				continue;
			}else{
				tp.second++;
				q.push(make_pair(b[tp.first][tp.second].val,tp));
			}
		}
//		for(int i=1;i<=sz;i++){
//			cerr<<z[i].val<<' ';
//		}
//		cerr<<'\n';
//		cerr<<'\n';
		int p=1,p1=1;
		while(p<=m||p1<=sz){
			if(p>m){
				if(find(z[p1].x)!=find(z[p1].y)){
					_union(z[p1].x,z[p1].y);
					sum+=z[p1].val;					
				}
				p1++;
			}else if(p1>sz){
				if(find(a[p].x)!=find(a[p].y)){
					_union(a[p].x,a[p].y);
					sum+=a[p].val;					
				}
				p++;
			}else if(a[p].val<z[p1].val){
				if(find(a[p].x)!=find(a[p].y)){
					_union(a[p].x,a[p].y);
					sum+=a[p].val;					
				}
				p++;
			}else{
				if(find(z[p1].x)!=find(z[p1].y)){
					_union(z[p1].x,z[p1].y);
					sum+=z[p1].val;					
				}
				p1++;
			}
//			cerr<<p<<' '<<p1<<'\n';
		}
//		cerr<<sum<<'\n';
		ans=min(ans,sum);
		return;
	}
	dfs(x+1);
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
}	
int main(){
//	cerr<<((sizeof(a)+sizeof(b)+sizeof(z)+sizeof(f)+sizeof(sz))>>20)<<'\n';
	fstream cin("road.in",ios::in);
	fstream cout("road.out",ios::out);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].val;
	}
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j].val;
			b[i][j].x=i+n;
			b[i][j].y=j;
		}
		sort(b[i]+1,b[i]+n+1,cmp);
	}
	sort(a+1,a+m+1,cmp);
//	cerr<<1<<'\n';
	clear();
	for(int i=1;i<=m;i++){
		if(find(a[i].x)!=find(a[i].y)){
			_union(a[i].x,a[i].y);
			e_vis[i]=1;
		}
	}
	vector<edge>s;
	for(int i=1;i<=m;i++){
		if(e_vis[i]){
			s.push_back(a[i]);
		}
	}
	m=0;
	for(auto i:s){
		a[++m]=i;
	}
//	cerr<<m<<'\n';
	dfs(1);		
	cout<<ans<<'\n';
	return 0;
}
