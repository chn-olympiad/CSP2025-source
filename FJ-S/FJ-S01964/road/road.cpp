#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int x,y,z;
	bool operator <(const node &t)const{
		if(z==t.z){
			if(y==t.y)return x<t.x;
			return y<t.y;
		}
		return z<t.z;
	}
	bool operator ==(const node &t)const{
		return x==t.x && y==t.y && z==t.z;
	}
}ed[1000010];
multiset<node> edg;
int c[15],a[15][10010],v[15];
struct union_find{
	int fa[10020],dep[10020];
	void init(int n){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			dep[i]=1;
		}
	}
	int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
	int merge(int x,int y){
		if(dep[x]>dep[y]){
			fa[y]=x;
			dep[y]=0;
		}else if(dep[x]<dep[y]){
			fa[x]=y;
			dep[x]=0;
		}else{
			fa[y]=x;
			dep[y]=0;
			dep[x]++;
		}
	}
};
ll ans=0,res=0;
void del(int x,int n){
	res-=c[x];
	for(int i=1;i<=n;i++)edg.erase(edg.find(node{n+x,i,a[x][i]}));
}
void add(int x,int n){
	res+=c[x];
	for(int i=1;i<=n;i++)edg.insert(node{n+x,i,a[x][i]});
}
vector<int> chg;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&ed[i].x,&ed[i].y,&ed[i].z);
	sort(ed+1,ed+1+m);
	union_find un;
	un.init(n);
	for(int i=1;i<=m;i++){
		int x=ed[i].x,y=ed[i].y,z=ed[i].z;
		int fx=un.find(x),fy=un.find(y);
		if(fx!=fy){
			un.merge(fx,fy);
			edg.insert(ed[i]);
			ans+=z;
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	chg.push_back(1);
	int siz=1;
	for(int i=2;i<=k;i++){
		chg.push_back(i);
		for(int j=0;j<siz;j++)chg.push_back(chg[j]);
		siz=siz*2+1;
	}
	for(int i:chg){
		if(v[i])del(i,n);
		else add(i,n);
		un.init(n+k);
		v[i]^=1;
		ll kres=0;
		for(node E:edg){
			int x=E.x,y=E.y,z=E.z;
			int fx=un.find(x),fy=un.find(y);
			if(fx!=fy){
				un.merge(fx,fy);
				kres+=z;
			}
		}
		ans=min(ans,res+kres);
	}
	printf("%lld",ans);
	return 0;
}
//80~100,17:31
