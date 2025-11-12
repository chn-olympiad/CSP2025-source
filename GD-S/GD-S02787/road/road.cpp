#include<bits/stdc++.h>

using namespace std;
#define cin fin
#define cout fout

const int N=1e4+9;

int n,m,k;
long long ans=0;

struct edge{
	int u,v,w;
}a[N];

int fa[N];

bool cmp(edge x,edge y){
	return x.w<y.w;
}

int gf(int x){
	while(x!=fa[x]) x=fa[x];
	return x;
//	if(x==fa[x]) return x;
//	else return fa[x]=gf(fa[x]);
}


int main(){
	ifstream fin("road.in");
	ofstream fout("road.out");
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		fa[i]=i;
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	
	int qq;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n+1;++j){
			cin>>qq;
		}
	}
	
	sort(a+1,a+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;++i){
		int uu=a[i].u,vv=a[i].v,ww=a[i].w;
		int uf=gf(uu),vf=gf(vv);
		if(uf!=vf){
			++cnt;
			fa[uf]=fa[vf];
			ans+=ww;
		}
		if(cnt>=n-1){
			cout<<ans;
			fin.close();
			fout.close();
			return 0;
		}
	}
	fin.close();
	fout.close();
	return 0;
}
