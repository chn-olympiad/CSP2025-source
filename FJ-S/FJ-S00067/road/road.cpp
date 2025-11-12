#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50;
const int M=1e6+50;
const int K=15;
typedef long long ll;
const ll INF=1e18;
typedef pair<int,int> pii;
int n,m,k;
struct Edge{
	int u,v,w;
} Es[M];
int a[K][N];
int fa[N];
int bb[M],tot;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
vector<pii> tt[M]; 
inline int read(){
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int x=0;
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
} 
inline ll solve(int sta){
	ll ans=0;
	for(int i=1;i<=tot;i++) tt[i].clear();
	for(int i=1;i<=m;i++) tt[Es[i].w].push_back(make_pair(Es[i].u,Es[i].v));
	int pop=n;
	for(int i=1;i<=k;i++){
		if((sta>>i-1)&1){
			pop++;
			ans+=a[i][0];
			for(int j=1;j<=n;j++) tt[a[i][j]].push_back(make_pair(i+n,j));
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1,cn=0;i<=tot&&cn<pop-1;i++){
		for(pii p:tt[i]){
			if(find(p.first)!=find(p.second)){
				//cout<<p.first<<" , "<<p.second<<" , "<<bb[i]<<endl; 
				fa[find(p.first)]=find(p.second);
				ans+=bb[i],cn++;
			}
		}
	}
	//cout<<sta<<" , "<<ans<<endl;
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) Es[i].u=read(),Es[i].v=read(),Es[i].w=read();
	sort(Es+1,Es+m+1,[](Edge A,Edge B){return A.w<B.w;});
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,cn=0;i<=m&&cn<n-1;i++){
		if(find(Es[i].u)!=find(Es[i].v)) fa[find(Es[i].u)]=find(Es[i].v),Es[++tot]=Es[i],bb[tot]=Es[i].w;
	}
	m=tot;
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) a[i][j]=read(),bb[++tot]=a[i][j];
	sort(bb+1,bb+tot+1),tot=unique(bb+1,bb+tot+1)-bb-1;
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) a[i][j]=lower_bound(bb+1,bb+tot+1,a[i][j])-bb;
	for(int i=1;i<=m;i++) Es[i].w=lower_bound(bb+1,bb+tot+1,Es[i].w)-bb;
	ll ans=INF;
	for(int s=0;s<(1<<k);s++) ans=min(ans,solve(s));
	printf("%lld",ans);
	return 0;
}

