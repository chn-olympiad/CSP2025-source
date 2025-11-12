#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,mp=0,k,a[11][11451],fa[11451];
int cr[10001][11];
bool ctp=0;
ll an=0,ans=1141145141919810,sq[1025],fr[1025];
struct edge{
	int f,t,w;
}p[2114514];
bool cmp(edge a,edge b){
	return a.w<b.w; 
}
int ffa(int x){
	if(fa[x]==x) return x;
	fa[x]=ffa(fa[x]);
	return fa[x];
}
void krus(){
	int kt=n-1;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,lf,rf;i<=m+mp;i++){
		lf=ffa(p[i].f);
		rf=ffa(p[i].t);
		if(lf!=rf){
			an+=p[i].w;
			fa[rf]=lf;
			kt--;
			if(kt==0) break;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p[i].f>>p[i].t>>p[i].w;
	}
	int itr;
	for(int i=1;i<=k;i++){
		itr=-1;
		for(int ii=0;ii<=n;ii++){
			cin>>a[i][ii];
			if(a[i][ii]==0&&ii!=0) itr=ii;
			cr[ii][1<<(i-1)]=a[i][ii];
		}
		if(itr!=-1&&a[i][0]==0){
		ctp=1;
		for(int ii=1;ii<=n;ii++){
			if(ii==itr) continue;
			mp++;
			p[m+mp].f=itr; p[m+mp].t=ii; p[m+mp].w=a[i][ii];
		}}
	}
	sort(p+1,p+m+mp+1,cmp);
	krus();
	//an=min(an,ans);
	cout<<an;
	return 0;
}
