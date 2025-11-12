#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int M=1e6+5;
struct line{
	int u,v,w;
}ls[M];
int q,k,c[10][N],cj[10],n,m,mp[N][N],f[N];
long long ans;
void adg(int u,int v,int w){
	ls[++q].v=v;
	ls[q].u=u;
	ls[q].w=w;
}
int getf(int x){
	if(f[x]==x) return x;
	else return getf(f[x]);
}
bool cmp(line a,line b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int a,b,w;
	for(int i=1;i<=m;++i){
		cin>>a>>b>>w;
		if(b>a) swap(a,b);
		if(mp[a][b]!=0) mp[a][b]=min(mp[a][b],w);
		else mp[a][b]=w;
	}
	if(k>0){
	for(int i=0;i<k;++i){
		cin>>cj[i];
		for(int j=1;j<=n;++j)
			cin>>c[i][j];
	}

	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int p=0;p<k;++p)
					mp[i][j]=min(mp[i][j],c[p][i]+c[p][j]+cj[p]);
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			adg(i,j,mp[i][j]);
	sort(ls+1,ls+q+1,cmp);
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=q;++i){
		if(getf(ls[i].u)!=getf(ls[i].v)){
			f[getf(ls[i].u)]=getf(ls[i].v);
			ans+=ls[i].w;
		}
	}
	cout<<ans;
	return 0;
}
