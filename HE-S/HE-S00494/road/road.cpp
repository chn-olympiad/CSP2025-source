#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10,M=1e6+10;

int n,m,k;
int f[N];
struct node{
	long long u,v,w;
};
vector<node> e;
long long ans;

bool cmp(node x,node y){
	return x.w<y.w;
}

int Find(int x){
	if(f[x]==x) return x;
	return f[x]=Find(f[x]);
}

void kru(){
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=0;i<e.size();i++){
		int rx=Find(e[i].u);
		int ry=Find(e[i].v);
		int w=e[i].w;
		if(rx!=ry){
			f[rx]=ry;
			ans+=w;
		}
	}
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		node x;
		cin>>x.u>>x.v>>x.w;
		e.push_back(x);
	}
	for(int i=1;i<=k;i++){
		long long c,a[N];
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				node x;
				x.u=u,x.v=v,x.w=a[u]+c+a[v];
				e.push_back(x);
			}
		}
	}
	kru();
	
	return 0;
}
