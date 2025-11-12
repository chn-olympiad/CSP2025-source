#include <bits/stdc++.h>
using namespace std;
const int N=2020000,M=1020000;
int head[N],ci[N],to[N],net[N],in[M],c[12],h;
int l[M],ans,e,final=2147483647;
struct node{
	int x,y;
}; 
node a[N];
bool cmp(node x,node y){
	return x.x<y.x;
}
void addedge(int x,int y,int z){
	to[++h]=y;
	head[h]=x;
	ci[h]=z;
	net[h]=in[x];
	in[x]=h;
}
int Find(int x){
	if(l[x]==x) return x;
	return Find(l[x]);
}
int U(int x,int y){
	int xx=Find(x),yy=Find(y);
	if(yy>xx) swap(xx,yy);
	l[xx]=yy;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		addedge(x,y,z);
		addedge(y,x,z);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			addedge(i+n,j,x);
			addedge(j,i+n,x);
		}
	}
	for(int j=0;j<(1<<k);j++){
		e=0;
		ans=0;
		for(int i=1;i<=m;i++) a[i].x=ci[i*2],a[i].y=i*2,e++;
		for(int i=1;i<=k;i++){
			if((j/(1<<(i-1)))%2){
				for(int s=in[i+n];s>0;s=net[s]){
					a[++e].x=ci[s],a[e].y=s;
				}
				ans+=c[i];
			}
		}
		sort(a+1,a+e+1,cmp);
		for(int i=1;i<=n;i++) l[i]=i;
		for(int i=1;i<=e;i++){
			//cout<<a[i].x<<' ';
			if(Find(head[a[i].y])==Find(to[a[i].y])) continue;
			U(head[a[i].y],to[a[i].y]);
			ans+=a[i].x;
		}
		final=min(final,ans);
	}
	cout<<final;
	return 0;
}