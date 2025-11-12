#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e4+500;
int n,m,k,fa[N];
long long ans=LLONG_MAX;
struct line{
	int u,v,w;
	bool operator < (const line &other) const{
		return w>other.w;
	}
};
priority_queue<line>pq;
struct node{
	int c,a[N];
}a[20];
inline int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int o;
inline void sget(){
	int mm=m,nn=n;
	long long res=0;
	for(register int i=0,j;i<k;++i){
		++nn;
		for(j=mm+1;j<=mm+n;j++){
			pq.push({nn,j-mm,a[i+1].a[j-mm]});
		}
		mm+=n;
		res+=a[i+1].c;
	}
	iota(fa+1,fa+nn+1,1);
	register int cnt=0,x,y;
	register line p;
	for(;cnt<nn-1;){
		p=pq.top();
		x=find(p.u),y=find(p.v);
		if(x!=y){
			fa[y]=x;
			res+=p.w;
			cnt++;
		}
		pq.pop();
	}
	ans=min(ans,res);
}
inline void get(priority_queue<line>g){
	int mm=m,nn=n;
	long long res=0;
	if(o){
		for(register int i=0,j;i<k;++i){
			if(o>>i&1){
				++nn;
				for(j=mm+1;j<=mm+n;j++){
					g.push({nn,j-mm,a[i+1].a[j-mm]});
				}
				mm+=n;
				res+=a[i+1].c;
			}
		}
	}
	iota(fa+1,fa+nn+1,1);
	register int cnt=0,x,y;
	register line p;
	for(;cnt<nn-1;){
		p=g.top();
		x=find(p.u),y=find(p.v);
		if(x!=y){
			fa[y]=x;
			res+=p.w;
			cnt++;
		}
		g.pop();
	}
	ans=min(ans,res);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(register int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		pq.push({u,v,w});
	}
	bool flag=1;
	for(register int i=1,j;i<=k;++i){
		cin>>a[i].c;
		if(a[i].c)flag=0;
		bool f=0;
		for(j=1;j<=n;++j){
			cin>>a[i].a[j];
			if(a[i].a[j]==0)f=1;
		}
		if(!f)flag=0;
	}
//	if(flag){
//		sget();
//	}else{
		for(o=0;o<(1<<k);++o){
			get(pq);
		}
//	}
	cout<<ans;
}
