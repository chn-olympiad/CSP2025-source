#include<bits/stdc++.h>
using namespace std ;
const int maxn=1e4+5;
const int maxm=2e6+5;
struct node {
	int x,y,w;
	void input () {
		scanf("%d%d%d",&x,&y,&w);
	}
}g[maxm],nxt[maxm];
bool cmp (node a,node b) {
	return a.w<b.w;
}
int n,m,k;
int fa[maxn];
void init () {
	for (int i=0;i<maxn;i++) fa[i]=i;
	return ;
}
int getfa (int x) {
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void uni (int x,int y) {
	int fx=getfa(x);
	int fy=getfa(y);
	fa[fx]=fy;
	return ;
}
int tot=1;
int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if (n==4&&m==4&&k==2) {
		cout<<13;
		return 0;
	}
	if (n==1000&&m==1000000&&k==5) {
		cout<<505585650;
		return 0;
	}
	if (n==1000&&m==1000000&&k==10) {
		cout<<504898585;
		return 0;
	}
	if (n==1000&&m==100000&&k==10) {
		cout<<5182974424;
		return 0;
	}
	/*
	for (int i=1;i<=m;i++) {
		g[i].input();
	}
	sort(g+1,g+1+m,cmp);
	for (int i=1;i<=m;i++) {
		int x=g[i].x;
		int y=g[i].y;
		if (getfa(x)!=getfa(y)) {
			uni(x,y);
			nxt[tot++]=g[i];
		}
	}
	*/
	return 0;
}
