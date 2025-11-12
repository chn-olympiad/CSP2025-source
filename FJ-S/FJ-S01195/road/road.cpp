#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;

struct sb {
	int v,l,w,u;
} e[N];
int la[N];

void add(int u,int v,int w,int i) {
	e[i].v=v;
	e[i].u=u;
	e[i].l=la[u];
	e[i].w=w;
	la[u]=i;
}

bool cmp1(sb a,sb b) {
	return a.w<b.w;
}

int f[N];

int fid(int a) {
	if(f[a]==0)return a;
	f[a]=fid(f[a]);
	return f[a];
}

void add(int a,int b) {
	f[fid(a)]=fid(b);
}

int n,m,k;
int d[15][N];

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w,i);
		add(v,u,w,i+m);
	}
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=n; j++) {
			cin>>d[i][j];  
		}
	}
	if(k==0) {
		sort(e+1,e+1+m,cmp1);
		int ans=0;
		for(int i=1; i<=n; i++) {
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(fid(u)==fid(v))continue;
			else {
				ans+=w;
				add(u,v);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	
	return 0;
}
