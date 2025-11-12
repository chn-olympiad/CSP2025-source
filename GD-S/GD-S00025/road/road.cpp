#include<bits/stdc++.h>
using namespace std;

const int N=1e6+15,T=1e4+15,INF=1e9+5;
int n,m,k,tx,ty,cnt,pos[12],id[12],d[12],fa[T];
pair<int,int>val[12][T];
long long ans,sum;
struct node{
	int x,y,w;
}a[N],now[T];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
long long work(int s){
	int tot=0,minn,who;
	long long res=0;
	for(int i=1;i<=k;++i) if(s&(1<<i-1)) id[++tot]=i,res+=d[i];
	for(int i=k+n;i;--i) fa[i]=i;
	for(int i=1;i<=tot;++i) pos[i]=1;
	for(int tp=1-tot,f=1;tp<n;++tp){
		while(f<=cnt&&find(now[f].x)==find(now[f].y)) ++f;
		for(int i=1;i<=tot;++i) while(pos[i]<=n&&find(id[i]+n)==find(val[id[i]][pos[i]].second)) ++pos[i];
		if(f<=cnt) minn=now[f].w,who=-1;
		else minn=INF,who=1;
		for(int i=1;i<=tot;++i){
			if(pos[i]<=n){
				if(val[id[i]][pos[i]].first<minn){
					minn=val[id[i]][pos[i]].first;
					who=i;
				}
			}
		}
		res+=minn;
		if(~who) fa[find(id[who]+n)]=find(val[id[who]][pos[who]].second);
		else fa[find(now[f].x)]=find(now[f].y);
	}
	return res;
}
void init(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) cin>>a[i].x>>a[i].y>>a[i].w;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int j=1;j<=k;++j){
		cin>>d[j];
		for(int i=1;i<=n;++i) cin>>val[j][i].first,val[j][i].second=i;
		sort(val[j]+1,val[j]+1+n);
	}
	for(int i=1;i<=m;++i){
		tx=a[i].x,ty=a[i].y;
		if(find(tx)!=find(ty)){
			fa[find(tx)]=find(ty);
			now[++cnt]=a[i];
			ans+=a[i].w;
			if(cnt==n-1) break;
		}
	}
	int mx=1<<k;
	for(int j=1;j<mx;++j) ans=min(ans,work(j));
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
