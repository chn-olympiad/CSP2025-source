#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ds{
	int fa[10050];
	ds(){
		for(int i=1;i<=10040;i++){
			fa[i]=i;
		}
	}
	int getfa(int x){
		if(fa[x]==x) return x;
		return fa[x]=getfa(fa[x]);
	}
	void un(int x,int y){
		fa[y]=x;
	}
}s1;
struct nd{
	int x,y,w;
}e[1000050],g[10050],h[12][10050];
bool operator<(const nd &a,const nd &b){
	return a.w<b.w;
}
bool operator>(const nd &a,const nd &b){
	return a.w>b.w;
}
int cnt;
int n,m,k,ans=1ll<<60;
int a[12][10050],c[15];
void mst1(){
	int ec=0;
	for(int i=1;i<=m;i++){
		int x=e[i].x,y=e[i].y;
		x=s1.getfa(x),y=s1.getfa(y);
		if(x!=y){
			s1.un(x,y);
			g[++ec]=e[i];
		}
		if(ec==n-1) return;
	}
}
int ret(int x,int y){
	return (x>>(y-1))&1;
}
void ca(int f){
	priority_queue<pair<nd,int>,vector<pair<nd,int>>,greater<pair<nd,int>>> q;
	int pos[15]={};
	int ed=n-1,res=0;
	for(int i=1;i<=k;i++){
		if(ret(f,i)){
			q.push({h[i][pos[i]+1],i});
			res+=c[i];
			ed++;
		}
	}
	q.push({g[pos[0]+1],0});
	s1=ds();
	while(!q.empty()){
		auto tp=q.top().first;
		int x=tp.x,y=tp.y,w=tp.w,id=q.top().second;
		q.pop();
		pos[id]++;
		if((id==0&&pos[id]==n-1)||(id!=0&&pos[id]==n));
		else{
//			cerr<<id<<" "<<pos[id]<<" "<<q.size()<<"\n";
			if(id==0) q.push({g[pos[0]+1],0});
			else q.push({h[id][pos[id]+1],id});
		}
		x=s1.getfa(x);
		y=s1.getfa(y);
		if(x!=y){
//			cerr<<x<<" "<<y<<" "<<w<<" "<<id<<"\n";
			s1.un(x,y);
			res+=w;
			ed--;
			if(ed==0) break;
		}
	}
//	cerr<<f<<" "<<ed<<" "<<res<<"\n";
	ans=min(ans,res);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].w;
	}
	sort(e+1,e+m+1);
	mst1();
//	cerr<<"*\n";
//	cerr<<clock()*1.0/CLOCKS_PER_SEC<<"\n";
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			h[i][j]={j,n+i,a[i][j]};
		}
		sort(h[i]+1,h[i]+n+1);
	}
//	cerr<<"*\n";
	for(int i=0;i<(1<<k);i++){
		ca(i);
	}
	cout<<ans<<"\n";
}
