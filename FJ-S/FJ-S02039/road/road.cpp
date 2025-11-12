#include <iostream>
#include <algorithm>
#define MAXX 1000005
#define MAXXN 10005
using namespace std;

int m,n=0,k,cnt=0,ans=0;
struct Edge{
	int u,v,w;
}e[MAXX];
int p[MAXXN];
bool cmp(Edge &a,Edge &b);
int Find(int a);
void Union(int a,int b);

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		if(Find(e[i].u)!=Find(e[i].v)){
			ans+=e[i].w;
			p[e[i].u]=e[i].v;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}

bool cmp(Edge &a,Edge &b){
	return a.w<b.w;
}

int Find(int a){
	if(p[a]==a) return a;
	else return p[a]=Find(p[a]);
}

void Union(int a,int b){
	int x=Find(a);
	int y=Find(b);
	if(x!=y){
		p[x]=y;
	}
	return;
}
