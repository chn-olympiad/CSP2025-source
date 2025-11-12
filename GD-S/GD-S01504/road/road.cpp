#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e4+5;
inline int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1),x+=(c-48),c=getchar();
	return x;
}
struct node{
	int u,v,w;
	bool operator<(const node& x) const{
		return w<x.w;
	} 
};
ll ans=0x3f3f3f3f3f3f3f3f,spend[15];
int fa[maxn],n,m,k,mmp[15][maxn],mini[15];
void pre(int n){
	for(int i=1;i<=n;i++) fa[i]=i;
}
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
inline void dfs(int dep,vector<node> mp,ll cost){
	if(dep>k){
		ll ls_ans=0;
		pre(n);
		sort(mp.begin(),mp.end());
		for(node i:mp){
			int x=find(i.u),y=find(i.v);
			if(x!=y){
				ls_ans+=i.w;
				fa[x]=y;
			}
		}
		ans=min(ans,ls_ans+cost);
		return;
	}
	dfs(dep+1,mp,cost);
	for(int i=1;i<=n;i++)
		mp.push_back({mini[dep],i,mmp[dep][i]});
	dfs(dep+1,mp,cost+spend[dep]);
} 
vector<node> a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		a.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		int minn=1e9+5;
		spend[i]=read();
		for(int j=1;j<=n;j++){
			mmp[i][j]=read();
			if(minn>mmp[i][j])
				minn=mmp[i][j],mini[i]=j;
		}
		spend[i]+=minn;
	}
	sort(a.begin(),a.end());
	pre(n);
	vector<node> mp;
	for(node i:a){
		int x=find(i.u),y=find(i.v);
		if(x!=y){
			ans+=i.w;
			fa[x]=y;
			mp.push_back({i.u,i.v,i.w});
		}
	}
	dfs(1,mp,0);
	cout<<ans;
	return 0;
} 
