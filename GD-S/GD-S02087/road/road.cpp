#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[11451],ans,tl,a[15][10005],sz;
struct nd{
	int u,v,w;
}e[1000005],g[1000005],ng[1000005];
bool cmp(nd x,nd y){
	return x.w<y.w;
}
int get(int x){
	if (fa[x]==x){
		return x;
	}
	return fa[x]=get(fa[x]);
}
void mg(int x,int y){
	fa[x]=y;
}
void kr(){
	int ct=0;
	for (int i=1;i<=m;i++){
		int u=get(e[i].u),v=get(e[i].v);
		if (u!=v){
			mg(u,v);
			ans+=e[i].w;
			g[++tl]=e[i];
			ct++;
		}
		if (ct==n-1){
			return ;
		}
	}
}
int cl(int tt){
	int ct=0,rs=0;
	for (int i=1;i<=sz;i++){
		int u=get(ng[i].u),v=get(ng[i].v);
		if (u!=v){
			mg(u,v);
			rs+=ng[i].w;
			ct++;
		}
		if (ct==tt-1){
			return rs;
		}
//		cout<<tt<<" "<<ct<<endl;
	}
//	cout<<ct<<endl;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for (int i=1;i<=k;i++){
		for (int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=n+10;i++){
		fa[i]=i;
	}
	kr();
	for (int i=1;i<(1<<k);i++){
		sz=0;
		for (int j=1;j<=tl;j++){
			ng[++sz]=g[j];
		}
		for (int j=1;j<=n+10;j++){
			fa[j]=j;
		}
		int x=0,y=0;	
//		cout<<i<<endl;
		for (int j=1;j<=k;j++){
			if (i & (1<<(j-1))){
				x+=a[j][0];
				y++;
				for (int l=1;l<=n;l++){
					ng[++sz]=nd{n+y,l,a[j][l]};
				}
			}
		}
		sort(ng+1,ng+sz+1,cmp);
		ans=min(ans,cl(n+y)+x);
	}
	cout<<ans;
	return 0;
}
/*
orz wj 
orz lxz
orz wsy
orz cyq
orz xza
*/
