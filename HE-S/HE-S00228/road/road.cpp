#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T&x) {
	x=0;
	char c;
	int sgin=1;
	do {
		c=getchar();
		if(c=='-')sgin=-1;
	} while(!isdigit(c));
	do {
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	} while(isdigit(c));
	x*=sgin;
}

struct node {
	int u,v,w;
} a[1000100];
int vis[11][100010],fa[100010];
map<int,map<int,int> > mp;
int n,m,k;

bool cmp(node a,node b){
	return a.w<b.w;
}

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	bool flag=false;
	for(int i=1; i<=m; i++) {
		read(a[i].u);
		read(a[i].v);
		read(a[i].w);
	}
	for(int i=1; i<=k; i++) {
		bool flagg=true;
		for(int j=0; j<=n; j++) {
			read(vis[i][j]);
			if(vis[i][j]!=0) {
				flagg=false;
			}
		}
		if(flagg)flag=true;
	}
	if(flag) {
		cout<<0;
		return 0;
	}
	int ans=0;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(a[i].u);
		int y=find(a[i].v);
		if(x!=y){
			ans+=a[i].w;
			fa[x]=fa[y];
		}
	}
	cout<<ans;
	return 0;
}
