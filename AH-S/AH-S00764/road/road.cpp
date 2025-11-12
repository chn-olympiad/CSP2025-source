#include <bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=1e6+5,S=1300,K=12;
const long long oo=100000000000000000;
int n,m,k;
int fa[N],cl,w[K],numc;
bool ok[N];
long long nc,ans=oo;
struct edge{
	int u,v,w;
}e[M],c[N*K],b[N],d[N][K],hp[N*K];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void clen(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool mer(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return 0;
	fa[fx]=fy;
	return 1;
}
void kru(){
	int neg=0;
	for(int i=1;i<=m&&neg<n-1;i++){
		int u=e[i].u,v=e[i].v;
		if(mer(u,v)){
			++neg;
			c[++cl]=e[i];
		}
	}
}
void dfs(int pos){
	if(pos==k+1){
		clen();
		int ncw=0;
		long long res=0;
		for(int i=1;i<=cl&&ncw<n-1+numc;i++){
			int u=c[i].u,v=c[i].v,w=c[i].w;
			if(mer(u,v)) ncw++,res+=1ll*w;
		}
		ans=min(ans,res+nc);
		return;
	}
	ok[pos]=0;
	dfs(pos+1);
	ok[pos]=1;
	int l=1,r=1,lc=1;
	while(lc<=cl+n){
		if(l==cl+1){
			hp[lc]=d[pos][r];
			r++;
			++lc;
			continue;
		}
		if(r==n+1){
			hp[lc]=c[l];
			l++;
			++lc;
			continue;
		}
		if(c[l].w<d[pos][r].w){
			hp[lc]=c[l];
			l++;
		}
		else{
			hp[lc]=d[pos][r];
			r++;
		}
		++lc;
	}
	
	nc+=1ll*w[pos];
	numc++;
	for(int i=1;i<=lc;i++) c[i]=hp[i];
	cl+=n;
	dfs(pos+1);
	int nm=0;
	for(int i=1;i<=cl;i++){
		if(c[i].u<pos+n) hp[++nm]=c[i];
	}
	for(int i=1;i<=nm;i++) c[i]=hp[i];
	nc-=1ll*w[pos];
	cl-=n;
	ok[pos]=0;
	numc--;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	}
	sort(e+1,e+m+1,cmp);
	clen();
	kru();
	for(int i=1;i<=k;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			b[j].u=i+n;
			b[j].v=j;
			b[j].w=x;
		}
		sort(b+1,b+n+1,cmp);
		for(int j=1;j<=n;j++) d[i][j]=b[j];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
