#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+100,M=1e6+100;
int n,m,k;
ll ans=0;
int c[15],a[15][N];
int top=0;
int father[N];
struct node{
	int u,v,w;
}e[M],s[M],p[M];
bool cmp(node p,node q){
	return p.w<q.w;
}
int find(int x){
	if(father[x]==x) return x;
	return father[x]=find(father[x]);
}
void unionn(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	father[fy]=fx;
}
void kruskal1(){
	int num=1;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		unionn(u,v);
		num++;
		ans+=w;
		s[++top]=e[i];
		if(num==n) break;
	}
}
ll kruskal2(int lim){
	int num=1;
	ll tmp=0;
	for(int i=1;i<=top;i++){
		int u=s[i].u,v=s[i].v,w=s[i].w;
		if(find(u)==find(v)) continue;
		unionn(u,v);
		num++;
		tmp+=w;
		if(num==lim||tmp>=ans) break;
	}
	return tmp;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) father[i]=i;
	kruskal1();
//	cout<<ans;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int S=1;S<=(1<<k)-1;S++){
		int record=top,num=n;
		ll tmp=0;
		for(int i=1;i<=top;i++) p[i]=s[i];
		for(int i=1;i<=k;i++){
			if(S&(1<<(i-1))){
				father[n+i]=n+i;
				num++;
				tmp+=c[i];
				for(int j=1;j<=n;j++) s[++top]={n+i,j,a[i][j]};
			}
		}
		sort(s+1,s+top+1,cmp);
		if(tmp<ans){
			for(int i=1;i<=n;i++) father[i]=i;
			ans=min(ans,tmp+kruskal2(num));
		}
		top=record;
		for(int i=1;i<=top;i++) s[i]=p[i];
	}
	cout<<ans;
	return 0;
}
